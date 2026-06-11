#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#define NDEBUG
#define SHOW(...) static_cast<void>(0)
//!===========================================================!//
//!  dP     dP                          dP                    !//
//!  88     88                          88                    !//
//!  88aaaaa88a .d8888b. .d8888b. .d888b88 .d8888b. 88d888b.  !//
//!  88     88  88ooood8 88'  '88 88'  '88 88ooood8 88'  '88  !//
//!  88     88  88.  ... 88.  .88 88.  .88 88.  ... 88        !//
//!  dP     dP  '88888P' '88888P8 '88888P8 '88888P' dP        !//
//!===========================================================!//
template <typename T, typename A>
std::istream& operator>>(std::istream& is, std::vector<T, A>& v)
{
    for (auto& e : v) { is >> e; }
    return is;
}
template <typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template <typename T>
std::vector<T> readVec(const std::size_t l)
{
    std::vector<T> v(l);
    for (auto& e : v) { std::cin >> e; }
    return v;
}
using ld = long double;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr unsigned int MOD = 1000000007;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template <typename F>
constexpr F PI = static_cast<F>(3.1415926535897932385);
std::mt19937 mt{std::random_device{}()};
template <typename T>
bool chmin(T& a, const T& b) { return a = std::min(a, b), a == b; }
template <typename T>
bool chmax(T& a, const T& b) { return a = std::max(a, b), a == b; }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T popCount(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : (T)__builtin_popcountll(u);
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f);
#endif
}
template <typename T>
constexpr T log2p1(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : T(64 - __builtin_clzll(u));
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = static_cast<unsigned long long>(v), v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), popCount(v);
#endif
}
template <typename T>
constexpr T clog(const T v) { return v == 0 ? T(0) : log2p1(v - 1); }
template <typename T>
constexpr T msbp1(const T v) { return log2p1(v); }
template <typename T>
constexpr T lsbp1(const T v)
{
#ifdef __has_builtin
    return __builtin_ffsll(v);
#else
    return v == 0 ? T(0) : popCount((v & (-v)) - T(1)) + T(1);
#endif
}
template <typename T>
constexpr bool ispow2(const T v) { return popCount(v) == 1; }
template <typename T>
constexpr T ceil2(const T v) { return v == 0 ? T(1) : T(1) << log2p1(v - 1); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : T(1) << (log2p1(v) - 1); }
//!============================================!//
//!    8888ba.88ba             oo              !//
//!    88  '8b  '8b                            !//
//!    88   88   88  .d8888b.  dP  88d888b.    !//
//!    88   88   88  88'  '88  88  88'  '88    !//
//!    88   88   88  88.  .88  88  88    88    !//
//!    dP   dP   dP  '88888P8  dP  dP    dP    !//
//!============================================!//
int main()
{
    const int N = read<int>();
    const ll A = read<ll>(), B = read<ll>();
    std::vector<int> p(N + 2, 0), r(N + 2, N + 1);
    p[0] = r[0] = 0, p[N + 1] = r[N + 1] = N + 1;
    std::vector<ll> C(N);
    for (int i = 1; i <= N; i++) { std::cin >> p[i], r[p[i]] = i; }
    auto LT = Vec(N + 2, N + 2, 0);
    for (int v = 0; v <= N + 1; v++) {
        LT[v][0] = (0 < v);
        for (int i = 1; i <= N + 1; i++) { LT[v][i] = LT[v][i - 1] + (p[i] < v); }
    }
    auto lessThan = [&](const int l, const int r, const int v) { return LT[v][r - 1] - (l == 0 ? 0 : LT[v][l - 1]); };
    std::vector<ll> dp(N + 2, INF<ll>);
    dp[0] = 0LL;
    for (int v = 1; v <= N + 1; v++) {
        const int i = r[v];
        for (int j = 0; j < i; j++) {
            if (p[j] > p[i]) { continue; }
            const int min = lessThan(j, i, p[j]);
            const int mid = lessThan(j, i, p[i]) - min - 1;
            const int max = lessThan(j, i, N + 1) - mid - min - 1;
            SHOW(v, i, j, min, mid, max);
            ll cost = dp[j] + (ll)min * B + (ll)max * A + (ll)mid * std::max(A, B);
            chmin(dp[i], cost);
        }
    }
    std::cout << dp[N + 1] << std::endl;
    return 0;
}
