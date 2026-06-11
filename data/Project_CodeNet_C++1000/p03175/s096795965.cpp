#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5+5;
const int M = 1e9+7;
vector<int> g[N];

pii dfs(int u, int p) {
    int w = 1, b = 1;
    for (auto &v : g[u]) {
        if (v != p) {
            pii x = dfs(v, u);
            int tot = (x.F + x.S) % M;
            w = (1ll * w * tot) % M;
            b = (1ll * b * x.F) % M;
        }
    }
    return {w, b};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    forn(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    pii x = dfs(0, -1);
    int ans = (x.F + x.S) % M;
    
    cout << ans << endl;
}
