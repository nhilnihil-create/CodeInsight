#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;


int digit(ll n) {
    int x = 0;
    while (n > 0) {
        n /= 10;
        x++;
    }
    return max(1, x);
}

signed main()
{
    int n;
    cin >> n;

    int d = digit(n);

    int cnt = 0;
    for (int D = 3; D <= d; D++) {
        ll n_pat = 1; rep(i, D) n_pat *= 3;
        rep (pat, n_pat) {
            ll t = pat;
            ll v = 0;
            int c7 = 0;
            int c5 = 0;
            int c3 = 0;
            rep(i, D) {
                if (t % 3 == 0) {
                    v = 10 * v + 7;
                    c7 ++;
                }
                else if (t % 3 == 1) {
                    v = 10 * v + 5;
                    c5++;
                }
                else {
                    v = 10 * v + 3;
                    c3++;
                }
                t /= 3;
            }

            if (c7 == 0 || c5 == 0 || c3 == 0) {
                continue;
            }

            if (v > n) {
                continue;
            }

            cnt++;
        }
    }

    put(cnt);

    return 0;
}