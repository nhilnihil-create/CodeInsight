#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e+9;


int main() {
    int H,W;
    cin >> H >> W;
    
    vector<vector<int>> dp(10,vector<int>(10,INF));
    REP(i,10) REP(j,10){
        cin >> dp[i][j];
    }
    //REP(i,10) dp[i][i] = 0;
    
    vector<vector<int>> A(H,vector<int>(W));
    vector<int> num(10,0);
    REP(i,H) REP(j,W){
        cin >> A[i][j];
        
        if ( A[i][j] == -1 ) continue;
        num[A[i][j]] += 1;
    }
    
    REP(k,10) REP(i,10) REP(j,10) {
        dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
    }
    
    ll ans = 0;
    
    for ( int i = 0; i <= 9; ++i){
        ans += ( num[i] * dp[i][1] );
    }
    
    cout << ans << endl;
    
    
    
    
    
    return 0;
}
