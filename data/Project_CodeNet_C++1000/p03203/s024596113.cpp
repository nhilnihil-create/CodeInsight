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
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 2e5+10;

ll H, W, N, X[MAX], Y[MAX];
vi hol[MAX];
set<ll> obsts;

ll solve() {
    swap(H, W);
    REP (i, N) {
        hol[Y[i]].push_back(X[i]);
        obsts.insert(X[i] * MAX + Y[i]);
    }

    ll ans = W, x = 0;
    FOR (h, 1, H+1) hol[h].push_back(W+1);
    FOR (h, 1, H+1) {
        sort(ALL(hol[h]));
        do { x++; } while (x <= W && obsts.find(x * MAX + h) != obsts.end());
        if (x > W) return ans;
        CHMIN(ans, *upper_bound(ALL(hol[h]), x) - 1);
    }
    return ans;
}

int main() {
    cin >> H >> W >> N;
    REP (i, N) cin >> X[i] >> Y[i];
    cout << solve() << endl;
}