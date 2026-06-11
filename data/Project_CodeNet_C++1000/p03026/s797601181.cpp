#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 1e4+10;

int N;
set<int> adj[MAX];
vi C;

void solve() {
    sort(ALL(C));
    ll sm = 0;
    REP (i, N-1) sm += C[i];
    cout << sm << endl;

    vi ret(N);
    queue<int> que;
    REP (i, N) if (adj[i].size() == 1) que.push(i);
    REP (i_c, N) {
        int i = que.front();
        que.pop();
        ret[i] = C[i_c];
        if (i_c == N-1) break;
        int next = *adj[i].begin();
        adj[i].erase(adj[i].begin());
        adj[next].erase(adj[next].find(i));
        if (adj[next].size() == 1) que.push(next);
    }
    FORE (x, ret) cout << x << " ";
    cout << endl;
}

int main() {
    cin >> N;
    REP (i, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    C = vi(N);
    REP (i, N) cin >> C[i];
    solve();
}