#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[2][3];
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < 3; ++i){
        if(c[0][i] != c[1][3-i-1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}