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
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
using namespace std;
signed main()
{
    int n;
    cin >> n;

    ll INF = 1e18;
    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    for (ll j = 1; j * 1 <= n; j++) {
        mins(dp[j], j);
    }

    rep(i, n+1) {
        for (ll v = 6; i + v <= n; v *= 6) {
            mins(dp[i+v], dp[i] + 1);
        }
        for (ll v = 9; i + v <= n; v *= 9) {
            mins(dp[i+v], dp[i] + 1);
        }
    }

    ll res = dp[n];
    put(res);

    return 0;
}