#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

void swapi(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition ( string array[], int array1[], int array2[], int l, int r) {

    string pivot = array[r];
    int pivoti = array1[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap (&array [i], &array [j]);
            swapi(&array1[i], &array1[j]);
            swapi(&array2[i], &array2[j]);
        }
        else if (array[j] == pivot) {
            if (array1[j] > pivoti) {
                i++;
                swap(&array[i], &array[j]);
                swapi(&array1[i], &array1[j]);
                swapi(&array2[i], &array2[j]);
            }
        }
    }
    swap (&array[i + 1], &array[r]);
    swapi(&array1[i + 1], &array1[r]);
    swapi(&array2[i + 1], &array2[r]);
    return (i + 1);
}

void quickSort( string array[], int array1[], int array2[], int l, int r) {
    if (l < r) {
        int pivot = partition(array, array1, array2, l, r);
        quickSort(array, array1, array2, l, pivot - 1);
        quickSort(array, array1, array2, pivot + 1, r);
    }
}

int main()
{
    int r, d, x;
    cin >> r >> d >> x ;
    
    rep(i,10){
        x = r*x - d;
         cout << x << endl;
    }
    
    return 0;
}
