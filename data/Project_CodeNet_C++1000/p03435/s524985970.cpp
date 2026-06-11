#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }

    int a[3][2];
    int b[2][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = c[i][j+1] - c[i][j];
            b[j][i] = c[j+1][i] - c[j][i];
        }
    }

    bool flag = true;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(a[i][j]!=a[i+1][j] || b[j][i]!=b[j][i+1]) flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}