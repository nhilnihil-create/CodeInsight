#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int A, B;
    cin >> A >> B;
    A--; B--;

    char C[100][100];
    rep(i,50) rep(j,100) C[i][j] = '.';
    rep(i,50) rep(j,100) C[i+50][j] = '#';

    int line = 0, row = 0;
    while(B > 0){
        if(row == 98){
            line += 2;
            row = 0;
        }

        C[line][row] = '#';
        row += 2;
        B--;
    }

    line = 99, row = 0;
    while(A > 0){
        if(row == 98){
            line -= 2;
            row = 0;
        }
        
        C[line][row] = '.';
        row += 2;
        A--;
    }

    cout << 100 << " " << 100 << endl;
    rep(i,100){
        rep(j,100) cout << C[i][j];
        cout << endl;
    }
}