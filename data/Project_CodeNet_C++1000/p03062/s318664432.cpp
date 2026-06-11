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
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll minus = 0, zero = 0;
    rep(i, n) {
        if (A[i] < 0) minus++;
        if (A[i] == 0) zero++;
    }

    ll res = 0;
    if (zero >= 1 || minus % 2 == 0) {
        rep(i, n) res += abs(A[i]);
    }
    else {
        // かならず1個だけ-になる
        ll v = 1e10;
        rep(i, n) {
            v = min(v, abs(A[i]));
        }

        rep(i, n) res += abs(A[i]);
        res -= 2 * v;
    }
    put(res);
}
signed main(){ Main();return 0;}