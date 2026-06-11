#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

typedef struct edge {
    int to;
    ll cost;
} edge;

vector<edge> G[100010];
bool v[100010];
vector<ll> X(100010);

void dfs(int x, ll D) {
    if (v[x]) return;
    v[x] = true;
    X[x] = D;
    for (auto e: G[x]) {
        dfs(e.to, e.cost+D);
    }
    return;
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    vector<ll> d(m);
    REP(i,m) {
        cin >> l[i] >> r[i] >> d[i];
        --r[i], --l[i];
        G[l[i]].push_back({r[i], d[i]});
        G[r[i]].push_back({l[i], -d[i]});
    }
    REP(i,100010) v[i] = false;
    REP(i,n) {
        dfs(i, 0);
    }
    REP(i,m) {
        if (X[r[i]]-X[l[i]] != d[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}