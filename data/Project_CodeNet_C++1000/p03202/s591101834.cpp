#include <bits/stdc++.h>

#define reg register
#define pr std::pair<int, int>
#define fi first
#define se second
#define FIN(s) freopen(s, "r", stdin)
#define FOUT(s) freopen(s, "w", stdout)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define lep(i, l, r) for (int i = l; i < r; ++i)
#define irep(i, r, l) for (int i = r; i >= l; --i)
#define ilep(i, r, l) for (int i = r; i > l; --i)
#define Rep(i, n) rep(i, 1, n)
#define Lep(i, n) lep(i, 1, n)
#define IRep(i, n) irep(i, n, 1)
#define ILep(i, n) ilep(i, n, 1)
typedef long long ll;
typedef long double ld;

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

namespace Base {
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
    template <typename Tp> inline void chmax(Tp &x, Tp y) { x < y ? x = y : 0; }
    template <typename Tp> inline void chmin(Tp &x, Tp y) { x > y ? x = y : 0; }
}; // namespace Base
using namespace Base;
/*----------------------------------------------------------------------------*/

#define MAX_N 300007

int N;
int a[MAX_N];
std::map<ll, ll> mp;

bool check(int lim) {
    mp.clear();
    Rep(i, N) if (a[i] <= a[i - 1]) {
        int tmp;
        while (!mp.empty() && (tmp = mp.rbegin()->first) > a[i]) {
            mp.erase(tmp);
        }
        tmp = a[i];
        while (tmp && mp[tmp] >= lim - 1)
            mp.erase(tmp--);
        if (!tmp)
            return false;
        mp[tmp]++;
    }
    return true;
}

int main() {
#ifdef LOCAL
    FIN("2.in");
#endif
    read(N);
    bool flag = true;
    Rep(i, N) read(a[i]), flag &= (a[i] > a[i - 1]);
    if (flag)
        return puts("1"), 0;
    int l = 2, r = N, mid, ans = -1;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}
