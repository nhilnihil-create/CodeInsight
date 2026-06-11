#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll x[100010];
ll y[100010];
ll z[100010];
vector<int> g[100010];

bool seen[100010];

void dfs(int v){
    seen[v] = true;
    for(auto nv : g[v]){
        if (seen[nv]) continue;
        seen[nv] = true;
        dfs(nv);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    rep(i, m) x[i]--, y[i]--;

    rep(i, m){
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }

    int cnt = 0;

    rep(i, n){
        if (seen[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}