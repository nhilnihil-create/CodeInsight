#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll N = 1e5+10, n, m;
vvll g(N), rev(N);
vll deg(N);

vll topo_sort(vvll &g, vll &deg, ll n){
    queue<ll> que;
    REP(i, n){
        if(!deg[i]) que.push(i);
    }
    vll ans;
    while(!que.empty()){
        ll s = que.front();
        que.pop();
        ans.push_back(s);
        for(auto j : g[s]){
            deg[j]--;
            if(deg[j] == 0) que.push(j);
        }
    }
    return ans;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    ll a, b;
    REP(i, n + m - 1){
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        rev[b].push_back(a);
        deg[b]++;
    }
    vll topo = topo_sort(g, deg, n);
    vll res(n, -1), pri(n);
    REP(i, n) pri[topo[i]] = i;
    res[topo[0]] = 0;
    REP(i, n){
        ll v = topo[i];
        ll ma = -1, idx = -1;
        for (auto u : rev[v]){
            if (pri[u] > ma){
                ma = pri[u];
                idx = u;
            }
        }
        res[v] = idx + 1;
    }
    REP(i, n) cout << res[i] << endl;
    return 0;
}