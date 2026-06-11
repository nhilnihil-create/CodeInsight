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
    ll n, m;
    cin >> n >> m;

    vector<ll> A(m);
    rep(i, m) cin >> A[i];
    sort(all(A));
    reverse(all(A));
    
    vector<ll> num = {
        0, 2, 5,5,4,5,6,3,7,6
    };

    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    rep(i, n) {
        rep(j, m) {
            if ((i+1)-num[A[j]] >= 0){
                dp[i+1] = max(dp[i+1], dp[(i+1)-num[A[j]]] + 1);
            }
        }
    }

    ll rest = n;
    for (ll i = 0; i < dp[n]; i++) {
        rep(j, m) {
            if (rest- num[A[j]] >= 0) {
                if (dp[rest] - 1 == dp[rest - num[A[j]]]) {
                    cout << A[j];
                    rest -= num[A[j]];
                    break;
                }
            }
        }
    }

    cout << endl;
}
signed main(){ Main();return 0;}