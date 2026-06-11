#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_H = 200, MAX_W = 200;

int H, W;
int c[10][10];
int A[MAX_H][MAX_W];

int main() {
    cin >> H >> W;
    REP(i, 10) {
        REP(j, 10) cin >> c[i][j];
    }
    REP(i, H) {
        REP(j, W) cin >> A[i][j];
    }
    
    REP(k, 10) {
        REP(i, 10) {
            REP(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        }
    }

    int min_mp = 0;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] != -1) min_mp += c[A[i][j]][1];
        }
    }
    PRINT(min_mp);
    return 0;
}