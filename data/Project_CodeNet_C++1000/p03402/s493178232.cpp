#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int A,B;
    cin >> A >> B;
    
    char c[100][100];
    REP(i,100) REP(j,100){
        if ( i < 50 ) c[i][j] = '#';
        else c[i][j] = '.';
    }
    
    int x = 0, y = 0;
    REP(a,A-1){
        c[x][y] = '.';
        y += 2;
        if ( y >= 100 ) {
            y = 0;
            x += 2;
        }
    }
    
    x = 60; y = 0;
    REP(b,B-1){
        c[x][y] = '#';
        y += 2;
        if ( y >= 100 ){
            y = 0;
            x += 2;
        }
    }
    
    cout << 100 << " " << 100 << endl;
    REP(i,100) REP(j,100){
        cout << c[i][j];
        if ( j == 99 ) cout << endl;
    }
    
    
    return 0;
}
