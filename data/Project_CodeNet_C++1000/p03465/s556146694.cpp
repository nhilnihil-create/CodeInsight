#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

namespace IO {
    #define gc getchar()
    template <typename t>
    inline void read(t& x) {
        x = 0; bool f = 1; char ch;
        for (ch = gc; ch < '0' || '9' < ch; ch = gc) if (ch == '-') f ^= 1;
        for (; '0' <= ch && ch <= '9'; ch = gc) x = (x << 3) + (x << 1) + (ch ^ 48);
        x = f ? x : -x;
    }
    #undef gc
}

const int MAXN = 2000 + 10;

int n, arr[MAXN], sum;

bitset<MAXN * MAXN> f;

int main() {
    IO::read(n);
    rep(i, 1, n) IO::read(arr[i]), sum += arr[i];
    f[0] = 1;
    rep(i, 1, n) f |= f << arr[i];
    rep(i, ceil(1.* sum / 2), sum) { if (f[i]) { printf("%d\n", i); return 0; } }
    return 0;
}