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
const int inf = 1e9;
const int mod = 1e9 + 7,
N = 2e5 + 11;

int L, n;
struct edge{
    int u, v, w;
    edge() {}
    edge(int _u, int _v, int _w) {
        u = _u, v = _v, w = _w;
    }
};
vector <edge> ans;
int main() {
    #ifdef makacha
        //Test();
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    read(L);
    n = __lg(L) + 1;
    for (int i = 1; i < n; i++) {
        ans.push_back(edge(i, i + 1, 0));
        ans.push_back(edge(i, i + 1, 1 << i - 1));
    }
    if ((1 << n - 1) != L)
        for (int i = 1; i < n; i++)
            if ((L >> i - 1 & 1)) {
                L -= 1 << i - 1;
                ans.push_back(edge(i, n, L));
            }
    cout << n << ' ' << ans.size() << '\n';
    for (auto e: ans)
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
}
