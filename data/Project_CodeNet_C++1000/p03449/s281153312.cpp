#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<vector<int>> grid(2, vector<int>(n));
    rep(i, 2){
        rep(j, n){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    rep(i, 2){
        rep(j, n){
            if(j < n-1) chmax(dp[i][j+1], dp[i][j] + grid[i][j+1]);
            if(i == 0) chmax(dp[i+1][j], dp[i][j] + grid[i+1][j]);
        }
    }
    cout << dp[1][n-1] << ln;
}
