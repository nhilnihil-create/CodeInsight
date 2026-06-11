#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;

void chmax(ll& x, ll y) {
    if (x < y) x = y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, q; cin >> n >> m >> q;

    vi L(m), R(m);
    REP(i, m) cin >> L[i] >> R[i];

    const int MAX = 1000;
    vector<vll> s(MAX, vll(MAX, 0));
    REP(i, m) {
        s[MAX-L[i]][R[i]]++;
    }

    FOR(i, 1, MAX) FOR(j, 1, MAX) {
        s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }

    debug(s);

    REP(_, q) {
        int l, r; cin >> l >> r;
        int sl = MAX - l, sr = MAX - r;

        print(s[sl][r] + s[sr - 1][l - 1] - s[sl][l - 1] - s[sr - 1][r]);
    }

}