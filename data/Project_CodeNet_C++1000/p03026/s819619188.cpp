#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

using Graph = vector<vector<int>>;

vector<int> ans(10010), c(10010); int cnt = 0;
void dfs(const Graph &G, int v, int p) { 
    ans[v] = c[cnt];
    cnt++;
	for (auto nv : G[v]) {
		if (nv == p)continue;
		dfs(G, nv, v);
	}
}

int main() {
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, n)cin >> c[i];
    c.resize(n); sort(rall(c));
    dfs(G, 0, -1);
    cout << accumulate(all(c), 0) - c[0] << endl;
    rep(i, n)cout << ans[i] << " ";
    cout << endl;
}