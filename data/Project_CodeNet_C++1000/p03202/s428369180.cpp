
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
int n, a[nsz + 5], ans;

int inline add_one(int as, int pos, map<int, int> &s) {
    if (as == 1)  return 0;
    for (int i = pos; i >= 1; --i) {
        if (as == 1) {
            cerr << i << ln;
        }
        if (s[i] < as - 1) {
            ++s[i];
            return 1;
        }
        s[i] = 0;
    }
    return 0;
}

bool inline chk(int as) {
    map<int, int> s;
    cont (i, n) {
        int p = a[i], pp = a[i - 1];
        if (p <= pp) {
            if (!add_one(as, p, s))  return 0;
        }
        s.erase(s.upper_bound(p), s.end());
    }
    return 1;
}

void inline solve() {
    int l = 0, r = nsz + 1, mid = (l + r) >> 1;
    for (; r - l > 1; mid = (l + r) >> 1) {
        (chk(mid) ? r : l) = mid;
    }
    ans = r;
}

int inline read() {
    int res = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); res *= 10, res += c ^ 48, c = getchar());
    return res;
}

void inline write(int a, char c) {
    int s = 0, d[10] = {0};
    for (; a; d[s++] = a % 10, a /= 10);
    for (s = s ? s : 1; s; putchar(d[--s] + 48));
    putchar(c);
}

int main() {
    n = read();
    cont (i, n) {
        a[i] = read();
    }
    solve();
    write(ans, ln);
}
