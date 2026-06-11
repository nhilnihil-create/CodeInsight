#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
vi adj[N];
int w[N];
set<pair<ll, int> > s;
vii ans;
ll D[N];
int n;

ll sum;

void dfs(int u, int par, int lvl) {
    sum += lvl;
    for (int nxt : adj[u]) {
        if (nxt == par)continue;
        dfs(nxt, u, lvl + 1);
    }
}


int main() {

#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    range(i, 1, n) {
        w[i] = 1;
        cin >> D[i];
        //D[i] += 5;
        s.insert({D[i], i});
    }

    while (SZ(s) > 1) {
        auto it = prev(s.end());
        ll have = it->fr;
        int idx = it->sc;
        ll need = have - (n - 2 * w[idx]);
        auto c = s.lower_bound({need, -1});
        if (c == s.end() || it == c || c->fr != need) {
            cout << -1 << endl;
            return 0;
        }
        w[c->sc] += w[idx];
        ans.push_back({idx, c->sc});
        s.erase(it);
    }

    for (auto edge : ans) {
        adj[edge.fr].push_back(edge.sc);
        adj[edge.sc].push_back(edge.fr);
    }

    dfs(s.begin()->sc, -1, 0);
    if (sum != s.begin()->fr) {
        cout << -1 << endl;
        return 0;
    }

    for (auto edge: ans)cout << edge.fr << " " << edge.sc << endl;

    return 0;

}