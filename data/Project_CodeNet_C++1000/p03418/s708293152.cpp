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

    ll res = 0;
    for (ll b = K + 1; b <= n; b++) {
        res += (b - K) * (n / b);
        res += max(0LL, 1 + (n % b) - K);
        if (K == 0) {
            res--; // a=0を除く
        }
    }

    put(res);
}
signed main(){ Main();return 0;}