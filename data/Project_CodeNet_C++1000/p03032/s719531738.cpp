#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, K;
    cin >> n >> K;
    vector<ll> V(n);
    rep(i, n) cin >> V[i];

    ll res = 0;
    for (int k = 0; k <= K; k++) {
        for (int l = 0; l <= n; l++) {
            for (int r = 0; r <= n - l; r++) {
                int back = k - l - r;
                if (back < 0 || l + r < back || l + r > n) {
                    continue;
                }
                vector<ll> u;
                ll sum = 0;
                rep(i, l) {
                    sum += V[i];
                    u.push_back(V[i]);
                }
                for (int i = n - 1; i >= n - r; i--) {
                    sum += V[i];
                    u.push_back(V[i]);
                }
                sort(all(u));
                rep(i, back) {
                    sum -= u[i];
                }

                res = max(res, sum);
            }
        }
    }
    put(res);
}
signed main(){ Main();return 0;}