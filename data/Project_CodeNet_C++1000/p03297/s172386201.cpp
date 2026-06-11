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

template <typename T> T gcd(T a, T b) { while (a) { b %= a; swap(a, b); } return b; }

// 自明なものに対する事前チェック
// first: pre_check で結果がわかったなら true
// second: 無限ループできる(Yes)なら true, first が false なら意味なし
pair<bool, bool> pre_check(ll A, ll B, ll C, ll D) {
    if(A < B || D < B) { return make_pair(true, false); }
    if(A % B > C) { return make_pair(true, false); }
    if(B <= C) { return make_pair(true, true); }
    if(B == D || D % B == 0) { return make_pair(true, true); }
    if(B-1 == C) { return make_pair(true, true); }

    // 初期位置
    ll X = A % B;
    ll Y = (D - B) % B;
    Y = gcd(Y, B);
    // C に一番接近するとき
    ll Z = X + ((C - X) / Y) * Y;
    if(Z + Y < B && Z + Y > C) {
        return make_pair(true, false);
    }
    else {
        return make_pair(true, true);
    }

    return make_pair(false, false);
}

// 愚直な解放で解く
// 無限ループできる(Yes)なら true
bool solve(ll A, ll B, ll C, ll D) {
    //pair<bool, bool> pre_result = pre_check(A, B, C, D);
    //if(pre_result.first) { return pre_result.second; }

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
#if 0
    // ABCD の全組み合わせを与える
    const ll max_abcd = 50;
    for(ll a = 1; a <= max_abcd; ++a) {
        for(ll b = 1; b <= max_abcd; ++b) {
            for(ll c = 1; c <= max_abcd; ++c) {
                for(ll d = 1; d <= max_abcd; ++d) {
                    pair<bool, bool> pre_result = pre_check(a, b, c, d);
                    if(pre_result.first) {
#  if 0
                        continue;
#  else
                        bool ret = solve(a, b, c, d);
                        if(pre_result.second != ret) {
                            DBG("%3lld %3lld %3lld %3lld pre_check: %s solve: %s\n",
                                    a, b, c, d, pre_result.second ? "Yes" : "No",
                                    ret ? "Yes" : "No");
                            assert(false);
                        }
#  endif
                    }
                    /*
                    if(!solve(a, b, c, d)) {
                        DBG("%3lld %3lld %3lld %3lld\n", a, b, c, d);
                    }
                    */
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
        pair<bool, bool> pre_result = pre_check(A, B, C, D);
        if(pre_result.second) { printf("Yes\n"); }
        else { printf("No\n"); }
    }
#endif
    return 0;
}
