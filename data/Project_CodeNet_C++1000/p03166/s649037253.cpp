#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 1e5 + 10 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int n , m , maxi , dp[maxn];
vector <int> edges[maxn] , revedges[maxn] , topol;
bool mark[maxn];

void dfs(int v) {
    mark[v] = 1;
    for (auto u : edges[v]) {
        if(!mark[u]) {
            dfs(u);
        }
    }
    topol.PB(v);
}

int32_t main() {
    FAST
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x , y; cin >> x >> y;
        x--; y--;
        edges[x].PB(y);
        revedges[y].PB(x);
    }
    for (int i = 0; i < n; ++i) {
        if(!mark[i]) {
            dfs(i);
        }
    }
    reverse(topol.begin() , topol.end());
    memset(mark , 0 , sizeof mark);
    for (int i = 1; i < n; ++i) {
        int v = topol[i];
        for (auto u : revedges[v]) {
            dp[v] = max(dp[v] , dp[u] + 1);
        }
        maxi = max(maxi , dp[v]);
    }

    cout << maxi << '\n';
 }
