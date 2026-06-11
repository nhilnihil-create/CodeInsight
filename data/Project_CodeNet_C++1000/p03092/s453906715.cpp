/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

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
const ll inf = 1e16;
const int mod = 1e9 + 7,
N = 5055;
int n, a[N];
ll A, B, f[N][N];
int main() {
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(n);
    read(A);
    read(B);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = inf;
    f[1][a[1]] = 0;
    f[1][0] = A;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i][j], f[i][j - 1]);
            if (a[i + 1] >= j) {
                f[i + 1][a[i + 1]] = min(f[i + 1][a[i + 1]], f[i][j]);
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + A);
            }
            else
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + B);
        }
    cout << f[n][n];
}

