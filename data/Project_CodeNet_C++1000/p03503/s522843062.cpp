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
int main()
{
    int n;
    cin >> n;
    vector<int> F(n * 10);
    rep(i, 10 * n) cin >> F[i];
    vector<ll> P(n * 11);
    rep(i, 11 * n) cin >> P[i];

    ll res = -1e17;
    rep(pat, 1 << 10) {
        if (pat == 0) {
            continue;
        }
        vector<int> c(n);
        rep(t, 10) {
            int j = t / 2;
            int k = t % 2;
            int open = (pat >> t) & 1;
            rep (i, n) {
                if (open * F[10 * i + 2 * j + k] > 0) {
                    c[i]++;
                }
            }
        }

        ll sum = 0;
        rep(i, n) {
            sum += P[11 * i + c[i]];
        }

        if (res < sum) {
            res = max(res, sum);
        }
    }
    put(res)

    return 0;
}