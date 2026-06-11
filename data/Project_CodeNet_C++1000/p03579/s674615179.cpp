#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

int BipartiteGraph(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> color(n, -1);
        int white_cnt = 0;
        function<bool (int, int, int)> dfs = [&](int u, int prev, int c) {
                color[u] = c;
                if (c == 1) white_cnt ++;
                for (auto v : g[u]) if (v != prev) {
                        if (color[v] == -1) {
                                if (!dfs(v, u, 1 - c)) return false;
                        } else if (color[v] != 1 - c) {
                                return false;
                        }
                }
                return true;
        };
        if (!dfs(0, -1, 0)) return -1;
        return white_cnt;
}

int main() {
	int n,m; cin>>n>>m;
	vector<vector<int>> a(n);
	rep(i,0,m){
		int u,v; cin>>u>>v;
		u--; v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt=BipartiteGraph(a);
	if(cnt==-1) printf("%lld",1LL*n*(n-1)/2-m);
	else printf("%lld",1LL*cnt*(n-cnt)-m);
  	return 0;
}
