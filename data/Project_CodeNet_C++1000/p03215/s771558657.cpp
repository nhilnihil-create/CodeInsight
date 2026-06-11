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
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, K; cin >> N >> K;
    VLL A(N); REP(i,N) cin >> A[i];

    int M = N * (N + 1) / 2;
    VLL B(M);
    int ib = 0;
    FOR(i, 0, N) {
        ll sum = 0;
        FOR(j, i, N) {
            sum += A[j];
            B[ib++] = sum;
        }
    }

    ll ans = 0;
    for (int i = 40; i >= 0; i--) {
        ll bit = ans + (1LL << i);
        int cnt = 0;
        for (auto b : B) {
            if ((bit & b) == bit) cnt++;
        }
        if (cnt >= K) {
            ans += (1LL << i);
        }
    }
    cout << ans << '\n';

    return 0;
}
