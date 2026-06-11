#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
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
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
static const double EPS = 1e-10;
static const double PI  = acos(-1.0);
static const ll MOD = 1000000007;
// static const ll MOD = 998244353;
static const int INF = 1 << 30;
// static const ll INF = 1LL << 62;
// --------------------------------------------------------


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int H, W, D; cin >> H >> W >> D;
    VVI A(H, VI(W)); REP(i,H) REP(j,W) cin >> A[i][j];
    int Q; cin >> Q;

    VP B(H*W+1);
    REP(h,H) REP(w,W) {
        B[A[h][w]] = make_pair(h, w);
    }

    VI C(H*W+1,0);
    int h1, h2, w1, w2;
    FOR(i,1,H*W+1-(D-1)) {
        tie(h1, w1) = B[i];
        tie(h2, w2) = B[i + D];
        C[i + D] = C[i] + abs(h1 - h2) + abs(w1 - w2);
    }

    REP(_, Q) {
        int L, R; cin >> L >> R;
        cout << C[R] - C[L] << '\n';
    }

    return 0;
}
