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
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl

const ll INF = 1ll<<61;

class WarchallFloyd {
private:
    int N;
    vvii E;

    void init(int n) {
        N = n;
        E = vvii(n);
    }

public:
    WarchallFloyd() {}
    WarchallFloyd(int n) { init(n); }

    void add(int from, int to, ll dist) {
        E[from].push_back(make_pair(to, dist));
    }

    vvi solve() {
        vvi ret(N, vi(N, INF));
        REP (i, N) FORE (e, E[i]) {
            ret[i][e.first] = e.second;
        }
        REP (i, N) ret[i][i] = 0;

        REP (k, N) REP (j, N) REP (i, N) {
            ret[j][i] = min(ret[j][i], ret[j][k] + ret[k][i]);
        }
        return ret;
    }
};

const int MAX = 210;

int H, W;
int C[10][10];
int A[MAX][MAX];

int solve() {
    WarchallFloyd wf(10);
    REP (i, 10) REP (j, 10) wf.add(i, j, C[i][j]);
    vvi c = wf.solve();

    int ret = 0;
    REP (h, H) REP (w, W) if (A[h][w] != -1) {
        ret += c[A[h][w]][1];
    }
    return ret;
}

int main() {
    cout << fixed << setprecision(15);
    cin >> H >> W;
    REP (i, 10) REP (j, 10) cin >> C[i][j];
    REP (i, H) REP (j, W) cin >> A[i][j];
    cout << solve() << endl;
}