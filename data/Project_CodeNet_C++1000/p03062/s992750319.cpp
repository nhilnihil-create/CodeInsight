#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    rep(i,n)cin >> a[i+1];
    vector<vector<ll>> dp(n+2,vector<ll>(2,0));
    dp[0][1] = -INF;
    repp(i,1,n+1){
        dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
    }
    cout << dp[n][0] << endl;
    return 0;
}