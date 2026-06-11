#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dpX[4001][16001];
int dpY[4001][16001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    S.push_back('T');
    int x, y;
    cin >> x >> y;
    int i = 0;
    while(S[i] == 'F'){
        x--;
        i++;
    }
    int X[8000] = {};
    int Y[8000] = {};
    int turn = 1;
    int tmp = 0;
    int ycnt = 0;
    int xcnt = 0;
    rep(j, S.length() - i) {
        if (S[j+i] == 'F') tmp++;
        else {
            turn = 1 - turn; 
            if (tmp != 0) {
                if (turn == 1) Y[ycnt++] = tmp;
                else X[xcnt++] = tmp;
                tmp = 0;
            }
        }
    }

    dpX[0][8000] = 1;
    dpY[0][8000] = 1;
    rep(i, 4000) {
        for(int j = 0; j <= 16000; j++) {
            if(dpX[i][j] == 1) {
                dpX[i+1][j-X[i]] = 1;
                dpX[i+1][j+X[i]] = 1;
            }
            if(dpY[i][j] == 1) {
                dpY[i+1][j-Y[i]] = 1;
                dpY[i+1][j+Y[i]] = 1;
            }
        }
    }
    /*
    rep(i,16000) if (dpX[4000][i] != 0) {
        cout << "dpX[" << i-8000 << "] = " << dpX[4000][i] << endl;
    }
    */
    if(dpX[4000][8000+x] == 1 && dpY[4000][8000+y] == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
