#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[3][3], x[3], y[3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    x[0]=0;
    for (int i=0; i<3; i++){
        y[i]=A[0][i];
    }
    for (int i=0; i<3; i++){
        x[i]=A[i][0]-y[0];
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (A[i][j]!=x[i]+y[j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}