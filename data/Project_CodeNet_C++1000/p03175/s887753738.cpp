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
template<class T>inline int popcount(T a) {return __builtin_popcount(a);}
//-------------------
constexpr int MX = 1e5+3;
vector<vector<int>> G(MX);
vector<vector<ll>> dp(MX, vector<ll>(2, -1));
int n;

void dfs(int node, int par) {
    if(dp[node][0]!=-1) return ;
    dp[node][0] = 1;
    dp[node][1] = 1;
    for(auto &e: G[node]) {
        if(e != par) {
            dfs(e, node);
            dp[node][0] *= dp[e][0] + dp[e][1];
            dp[node][0] %= mod;
            dp[node][1] *= dp[e][0];
            dp[node][1] %= mod;
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    cin >> n;
    rep(i,n-1) {
        int x,y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1])%mod << endl;
    return 0;
}
