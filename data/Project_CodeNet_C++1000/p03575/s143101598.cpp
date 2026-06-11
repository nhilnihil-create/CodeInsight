#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs ( int now, vector<vector<int>> &g, vector<bool> &flg, pair<int, int>  p ) {
    if ( flg[now] ) return;
    flg[now] = true;
    for ( auto u : g[now] ) {
        if ( u == p.first && now == p.second || u == p.second && now == p.first ) continue;
        if ( flg[u] ) continue;
        dfs(u, g, flg, p);
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> pv(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
        pv[i] = make_pair(a, b);
    }
    int ans = 0;
    rep(i, m) {
        vector<bool> flg(n, 0);
        dfs(0, g, flg, pv[i]);
        rep(j, n) {
            if ( !flg[j] ) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
