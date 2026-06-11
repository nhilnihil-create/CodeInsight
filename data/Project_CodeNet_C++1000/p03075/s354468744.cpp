#include <bits/stdc++.h>

/**
 * [IPC - Contest III]
 * @author Rodrigo Moreira Pires de Andrade
 * @version 13/04/2020
*/

using namespace std;

// Functions and class come here..
bool Solvef(int *a, int n, int k) {

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((a[j] - a[i]) > k)
                return false;
        }
    }

    return true;
}

int main() {

    int solve[5];
    int maxsize;

    for(int i = 0; i < 5; i++) 
        cin >> solve[i];

    cin >> maxsize;

    if(Solvef(solve, 5, maxsize)) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
