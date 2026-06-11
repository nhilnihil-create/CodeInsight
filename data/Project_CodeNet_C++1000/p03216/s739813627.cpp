#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n, q;
    string s;
    cin >> n >> s >> q;
    for (Int i = 0; i < q; i++) {
        Int len;
        cin >> len;
        Int res = 0;
        Int cur = 0;
        Int d, m, c, dm, mc, dmc;
        d = m = c = dm = mc = dmc = 0;
        while (cur < len) {
            if (s[cur] == 'D') {
                d++;
            } 
            if (s[cur] == 'M') {
                m++;
                dm += d;
            } 
            if (s[cur] == 'C') {
                c++;
                mc += m;
                dmc += dm;
            }
            cur++;
        }
        res += dmc;
        while (cur < n) {
            if (s[cur - len] == 'D') {
                d--;
                dm -= m;
                dmc -= mc;
            }
            if (s[cur - len] == 'M') {
                m--;
                mc -= c;
            }
            if (s[cur - len] == 'C') {
                c--;
            }
            if (s[cur] == 'D') {
                d++;
            }
            if (s[cur] == 'M') {
                m++;
                dm += d;
            }
            if (s[cur] == 'C') {
                c++;
                mc += m;
                dmc += dm;
                res += dm;
            }
            cur++;
        }
        dump(res);
    }
    return 0;
}