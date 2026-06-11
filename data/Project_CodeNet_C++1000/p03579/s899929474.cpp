#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) __builtin_clzll(x)
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
#define cinfast() cin.tie(0), ios::sync_with_stdio(false)
#define PERM(c)                                                                \
    sort(All(c));                                                              \
    for(bool cp = true; cp; cp = next_permutation(All(c)))
#define MKORDER(n)                                                             \
    vector<int> od(n);                                                         \
    iota(All(od), 0LL);

template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
template <class Head> inline void COUT(Head &&head) { cout << head << "\n"; }
template <class Head, class... Tail>
inline void COUT(Head &&head, Tail &&... tail) {
    cout << head << " ";
    COUT(forward<Tail>(tail)...);
}

#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    long long __VA_ARGS__;                                                     \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

// generic lambdas
template <typename F>
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) &&                                                     \
    (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    static inline constexpr decltype(auto)
    fix(F &&f) noexcept {
    return [f = std::forward<F>(f)](auto &&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
}

template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18;
const double PI = atan(1.0) * 4.0;
const ll dw[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dh[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define PI 3.141592653589793238

//二部グラフ判定
ll color[100100];
VVL g;

bool bpdfs(ll v, ll c) {
    color[v] = c;
    FOREACH(next, g[v]) {
        if(color[next] == c)
            return false;
        else if(color[next] == 0 && !bpdfs(next, -c))
            return false;
    }
    return true;
}

signed main() {
    LCIN(N, M);
    VL A(M), B(M);
    g.resize(N);
    REP(i, M) {
        LCIN(u, v);
        u--, v--;
        A[i] = u, B[i] = v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    ll ans = N * (N - 1) / 2 - M;
    if(bpdfs(0, 1)) {
        ll b = 0, w = 0;
        REP(i, N) {
            if(color[i] == 1)
                b++;
            else
                w++;
        }
        ans = b * w;
        REP(i, M) {
            if(color[A[i]] != color[B[i]]) ans--;
        }
    }
    cout << ans << "\n";
}