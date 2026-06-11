#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int N = 2e5+5;

int n;
vector<int> al[N];

ii dfs(int u, int p) {
    ii cur = ii(u,-1);
    for (auto v : al[u]) if (v != p) {
        ii nxt = dfs(v, u);
        if (nxt.sc > cur.sc) cur = nxt;
    }
    cur.sc += 1;
    //cout << u << " " << cur.fi << " " << cur.sc << endl;
    return cur;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i,1,n-1){
        int x, y; cin >> x >> y;
        al[x].pb(y);
        al[y].pb(x);
    } 

    int u = dfs(1,0).fi;
    cout << (dfs(u,0).sc % 3 == 1 ? "Second" : "First") << '\n';
}

