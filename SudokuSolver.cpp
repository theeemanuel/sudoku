#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int row, col, grid[9][9];
long int calls = 0;

int findEmptyCell()
{
   int i, j;

   for (i = 0; i < 9; i++)
      for (j = 0; j < 9; j++)
      {
         if (grid[i][j] == 0)
         {
            row = i;
            col = j;
            return 1;
         }
      }
   return 0;
}

int validity(int cellRow, int cellCol, int num)
{
   int i, j, trow, tcol, trow1, tcol1;
   int rowStart = (cellRow / 3) * 3;
   int colStart = (cellCol / 3) * 3;

   for (j = 0; j < 9; j++)
   {
      if (grid[cellRow][j] == num)
         return 0;
      if (grid[j][cellCol] == num)
         return 0;
   }

   for (i = rowStart; i < rowStart + 1; i++)
      for (j = colStart; j < colStart + 1; j++)
         if (grid[i][j] == num)
            return 0;

   return 1;
}

int sudokuSolver()
{

   int digit;
   int prevRow, prevCol; 
   calls++;

   if (!findEmptyCell())
      return 1;

   for (digit = 1; digit <= 9; digit++)
   {
      if (validity(row, col, digit))
      {
         grid[row][col] = digit;
         prevRow = row;
         prevCol = col;
         if (sudokuSolver())
            return 1;
         row = prevRow;
         col = prevCol;
         grid[row][col] = 0;
      }
   }

   return 0;
}

void printGrid()
{

   int i, j;

   printf("\t-------------------------\n");
   for (i = 0; i < 9; i++)
   {
      printf("\t");
      for (j = 0; j < 9; j++)
      {
         if (j == 0)
            printf("| ");
         if (grid[i][j] == 0)
            printf(". ");
         else
            printf("%d ", grid[i][j]);
         if ((j + 1) % 3 == 0)
            printf("| ");
      }

      if ((i + 1) % 3 == 0)
         printf("\n\t-------------------------");

      printf("\n");
   }
}

int main()
{

   int i, j, solution = 0;
   char ch;
   system("cls");
   printf("Enter the Sudoku puzzle (0 in vacant cells): \n");
   for (i=0; i<9; i++)
   {
      for (j=0; j<9; j++)
         scanf("%d" ,&grid[i][j]);
   }
   system("cls");
   printf("The Entered Sudoku puzzle is: \n");
   printGrid();
   printf("Press 'c' to confirm and solve, or 'e' to exit: ");
   ch = getch();
   if (ch == 'e')
      exit(0);
   else if (ch == 'c')
   {
      system("cls");
      solution = sudokuSolver();
      if (solution)
      {
         printf("\nThe Solved Sudoku is: \n\n");
         printGrid();
      }
      else
         printf("\nNo Possible Solution!!\n\n");
      getch();
   }
}
