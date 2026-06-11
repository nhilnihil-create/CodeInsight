#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define ALL(v) v.begin(), v.end()

const int MAX = 1e5+10;
int N;
vi D, c, p;
vii P;
vi children[MAX];

ii dfs(int n) {
    int cnt = 0;
    ll res = 0;
    FORE (ch, children[n]) {
        ii r = dfs(ch);
        cnt += r.first;
        res += r.second;
    }
    res += cnt;
    return MP(cnt+1, res);
}

int main () {
    cin >> N;
    D = vi(N);
    c = vi(N, 1);
    p = vi(N, -1);
    REP (i, N) {
        cin >> D[i];
        P.PB(MP(D[i], i+1));
    }
    sort(ALL(D));
    sort(ALL(P));
    FORR (i, 1, N) {
        ll d = D[i] - N + 2*c[i];
        auto it = lower_bound(ALL(D),d);
        if (it == D.end() || *it != d) {
            cout << -1 << endl;
            return 0;
        }
        int j = it-D.begin();
        c[j] += c[i];
        p[i] = j;
        children[j].PB(i);
    }
    if (dfs(0).second != D[0]) {
        cout << -1 << endl;
        return 0;
    }
    REP (i, N) if (p[i] != -1) {
        cout << P[p[i]].second << " " << P[i].second << "\n";
    }
}