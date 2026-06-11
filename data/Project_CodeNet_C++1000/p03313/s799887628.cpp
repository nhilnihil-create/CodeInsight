/**
    *Makacha
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> inline void read (T &x) {bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x<<3) + (x<<1) + c - 48; if (b)x=-x;}
template <typename T> inline void wrip(T x) {if (x > 9) wrip(x / 10); putchar(x%10 + 48); }

template <typename T> inline void write(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar(' ');}
template <typename T> inline void writeln(T x) {if (x < 0) putchar('-'), x = -x; wrip(x); putchar('\n');}
inline char readch() {char c; do c = getchar(); while (c == '\n' || c == ' '); return c;}
inline void reads(string &s) {char c; while((c=getchar())==' '||c =='\n'); s=c; while((c=getchar())!=' '&&c!='\n') s+=c;}
inline void getlines(string &s) {char c; while((c=getchar())=='\n'); s=c; while((c=getchar())!='\n') s+=c;}
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;

const ld pi = acos(-1);
const int inf = 2e9 + 11;
const int mod = 1e9 + 7;
const int N = 1e6 + 11;

int n, m, res, a[N], tg[N];
ii f[N];
#define lastbit(x) (__builtin_ctz(x))
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif //makacha
    read(m);
    n = 1 << m;
    for (int i = 0; i < n; i++)
        read(a[i]);
    for (int i = 0; i < n; i++)
        f[i].fi = a[i];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if ((i >> j & 1)) {
                int k = i ^ (1 << j);
                tg[0] = f[i].fi,
                tg[1] = f[i].se,
                tg[2] = f[k].fi,
                tg[3] = f[k].se,
                sort(tg, tg + 4);
                f[i] = ii(tg[3], tg[2]);
            }
    for (int i = 1; i < n; i++) {
        res = max(res, f[i].fi + f[i].se);
        writeln(res);
    }
}
