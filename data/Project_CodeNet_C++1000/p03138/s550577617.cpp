#include <bits/stdc++.h>
using namespace std;

// template {{{
#define  range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)

#define  whole(f, x, ...) ([&](decltype((x)) container) { return (f)(  begin(container),  end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

// constexpr i32 mod   = 998244353;
constexpr i32 mod   = 1e9 + 7;
constexpr i32 inf   = 1001001001;
constexpr i64 infll = 1001001001001001001ll;

constexpr int dx[] = {0, -1, 1, 0, -1, 1, -1, 1};
constexpr int dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};

struct IoSetup { IoSetup(int x = 15){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

template <typename T = i64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }

template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }

template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// }}}

void solver() {
    i64 N, K;
    cin >> N >> K;

    vector< i64 > A(N);
    cin >> A;

    vector< i64 > r_(41);
    auto r = r_.begin() + 1;
    range(i, 0, 40) {
        i64 sum0 = 0, sum1 = 0;
        i64 msk = (1ll << i); 
        range(j, 0, N) {
            i64 a = msk & A[j];
            sum0 += a;
            sum1 += msk ^ a;
        }

        r[i] = r[i - 1] + max(sum1, sum0);
    }

    i64 ans = 0;
    range(j, 0, N) {
        ans += A[j] ^ K;
    }

    range(i, 0, 40) {
        i64 msk = (1ll << i);
        if (!(msk & K)) continue;

        K -= msk;

        i64 sum = 0;
        range(j, 0, N) {
            sum += ((A[j] >> i) << i) ^ K;
        }

        chmax(ans, sum + r[i - 1]);
    }

    cout << ans << endl;
}

signed main(int argc, char *argv[]) {
    solver();
}
