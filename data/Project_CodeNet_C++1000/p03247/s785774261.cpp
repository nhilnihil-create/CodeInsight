#include <bits/stdc++.h>

namespace IO {
    template <typename Tp> inline Tp input() {
        Tp x = 0, y = 1;
        char c = getchar();
        while ((c < '0' || '9' < c) && c != EOF) {
            if (c == '-')
                y = -1;
            c = getchar();
        }
        if (c == EOF)
            return 0;
        while ('0' <= c && c <= '9')
            x = x * 10 + c - '0', c = getchar();
        return x *= y;
    }
    template <typename Tp> inline void read(Tp &x) { x = input<Tp>(); }
}; // namespace IO
using namespace IO;

namespace modular {
    const int MOD = 1000000007;
    inline int add(int x, int y) { return (x += y) >= MOD ? x -= MOD : x; }
    inline void inc(int &x, int y) { (x += y) >= MOD ? x -= MOD : 0; }
    inline int mul(int x, int y) { return 1LL * x * y % MOD; }
    inline int qpow(int x, int y) {
        int ans = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1)
                ans = mul(ans, x);
        return ans;
    }
}; // namespace modular

#define reg register
#define MAX_N 1007
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
typedef long long ll;

int N, tot, top, bs;
ll d[MAX_N];

struct point {
    ll x, y;
} p[MAX_N];
typedef point P;

void print(ll x, ll y, int k) {
    if (k <= 0)
        return;
    if (y >= 0) {
        if (std::abs(x) <= y)
            putchar('U'), print(x, y - d[k], k - 1);
        else {
            if (x < 0)
                putchar('L'), print(x + d[k], y, k - 1);
            else
                putchar('R'), print(x - d[k], y, k - 1);
        }
    } else {
        if (std::abs(x) <= -y)
            putchar('D'), print(x, y + d[k], k - 1);
        else {
            if (x < 0)
                putchar('L'), print(x + d[k], y, k - 1);
            else
                putchar('R'), print(x - d[k], y, k - 1);
        }
    }
}

void solve() {
    ll mx = 0;
    rep(i, 1, N) mx = std::max(mx, p[i].x + p[i].y);
    while ((1LL << tot) + 1 + bs < mx)
        tot++;
    if (bs)
        d[++top] = 1;
    rep(i, 0, tot) d[++top] = (1LL << i);
    printf("%d\n", top);
    irep(i, top, 1) printf("%lld ", d[i]);
    puts("");
    rep(i, 1, N) print(p[i].x, p[i].y, top), puts("");
}

int main() {
#ifdef LOCAL
    FIN("in");
#endif
    read(N);
    rep(i, 1, N) read(p[i].x), read(p[i].y);
    int k = p[1].x + p[1].y;
    k &= 1;
    rep(i, 1, N) if (((p[i].x + p[i].y) & 1) != k) return puts("-1"), 0;
    if (!k)
        bs = 1;
    solve();
    return 0;
}
