#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//-------------------
constexpr int MX = 405;
vector<ll> a(MX);
vector<vector<ll>> dp(MX, vector<ll>(MX, LINF));

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    int n; cin >> n;
    rep(i,n) cin >> a[i];

    rep(i,n) dp[i][i] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n-i;j++) {
            ll sm = 0;
            ll res = LINF;
            for(int k=j;k<j+i;k++) {
                sm += a[k];
                chmin(res, dp[j][k]+dp[k+1][j+i]);
            }
            sm += a[j+i];
            dp[j][j+i] = res+sm;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
