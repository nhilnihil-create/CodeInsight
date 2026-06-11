#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010
//#define CHECK

template <typename T> T gcd(T a, T b) { while (a) { b %= a; swap(a, b); } return b; }

// 無限ループできる(Yes)なら true
bool solve(ll A, ll B, ll C, ll D) {
    if(A < B || D < B) { return false; }
    if(A % B > C) { return false; }
    if(B <= C) { return true; }
    if(B == D || D % B == 0) { return true; }
    if(B-1 == C) { return true; }

    // 初期位置
    ll X = A % B;
    // X から、  D を加算することで gcd(Y, B) の位置に訪れることになる
    ll Y = (D - B) % B;
    Y = gcd(Y, B);
    // C に一番接近するとき
    ll Z = X + ((C - X) / Y) * Y;
    if(Z + Y < B && Z + Y > C) {
        // NG ゾーンに入った
        return false;
    }

    // NG ゾーンに入ることなく無限ループできる
    return true;
}

// 愚直な解放で解く
// 無限ループできる(Yes)なら true
bool brute_force(ll A, ll B, ll C, ll D) {
    map<ll, bool> exist;
    ll cur = A;
    exist[A] = true;
    for(;;) {
        cur -= B;
        if(cur < 0) { return false; }
        if(cur <= C) { cur += D; }
        if(exist.count(cur) != 0) { break; }
        exist[cur] = true;
    }
    return true;
}

signed main()
{
#ifdef CHECK
    // ABCD の全組み合わせを与える
    const ll max_abcd = 30;
    for(ll a = 1; a <= max_abcd; ++a) {
        for(ll b = 1; b <= max_abcd; ++b) {
            for(ll c = 1; c <= max_abcd; ++c) {
                for(ll d = 1; d <= max_abcd; ++d) {
                    bool cand = solve(a, b, c, d);
                    bool ans = brute_force(a, b, c, d);
                    if(cand != ans) {
                        DBG("%3lld %3lld %3lld %3lld cand: %s ans: %s\n",
                                a, b, c, d, cand ? "Yes" : "No", ans ? "Yes" : "No");
                        assert(false);
                    }
                }
            }
        }
    }
#else
    ll T;
    cin >> T;
    REP(t, T) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        bool ans = solve(A, B, C, D);
        if(ans) { printf("Yes\n"); }
        else { printf("No\n"); }
    }
#endif
    return 0;
}
