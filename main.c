/*This program helps you identify the user the unique number in the array, through certain numbers given by the user
 *
 * Author:Karla Alexandra Hernandez Aviles
 * Email:A01411843@itesm.mx
 * Date:15/10/2018
 * 
 * */

#include <stdio.h>
#include <stdlib.h>

int CompFunct(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    // Declaration if variables
    int k;
    int n;
    int count;
    int cant;

    // In this part the program ask to the user how many numbers want to use
    printf("Welcome user, this program will help you to identify the unique;"
           "How many numbers would you like to use?\n");
    scanf("%i", &n);

    //Declare variable for the size of numbers of variables that the user want
    int arr[n];

    // in this part asks for the value and stores it in the array
    for (int a = 0; a < n; a++) {
        printf("Give me the number would you like:\n", a + 1);
        scanf("%i", &k);
        arr[a] = k;
    }

    // In this part the program order the numbers in the array from smallest to biggest.
    qsort(arr, n, sizeof(int), CompFunct);
    printf("The unique numbers in the array you gave me are:\n");

    // In this part prints the unique numbers.
    for (int a = 0; a < n; a += count+1) {
        count = 0;
        // In this part compare the numbers
        do {
            // Compares the number in the current position with the next one or the one after.......
            if (arr[a] == arr[a+count+1]) {
                count++;
                cant = 1;
            } else {
                cant = 0;
            }
        } while (cant == 1);

        // If no duplicates were found, the number is unique and should be printed.
        if (count == 0) {
            printf("%i\n", arr[a]);
        }
    }
    return 0;
}