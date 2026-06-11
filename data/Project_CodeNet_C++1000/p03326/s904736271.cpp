#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// const int INF = 1 << 30;
const ll INF = 1LL << 62;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, M; cin >> N >> M;
    VLL x(N), y(N), z(N); REP(i,N) cin >> x[i] >> y[i] >> z[i];

    ll ans = -INF;
    for (int bit = 0; bit < (1 << 3); bit++) {
        ll a = (bit & (1 << 0)) ? -1 : 1;
        ll b = (bit & (1 << 1)) ? -1 : 1;
        ll c = (bit & (1 << 2)) ? -1 : 1;
        VLL d(N);
        REP(i, N) d[i] = a * x[i] + b * y[i] + c * z[i];
        RSORT(d);
        ll total = 0;
        REP(i, M) total += d[i];
        ans = max(ans, total);
    }
    cout << ans << '\n';

    return 0;
}
