#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }




int main() {
    ll n,m; cin >> n >> m;
    if(n == 1) {
        if(m == 1) {
            cout << 1 << endl;
            return 0;
        }
        cout << m - 2 << endl;
        return 0;
    } else {
        if(m == 1) {
            cout << n-2 << endl;
            return 0;
        }
        ll ans = m*n - 4;
        if(n > 2) {
            ans -= 2*(n-2);
        }
        if(m > 2) {
            ans -= 2*(m-2);
        }
        cout << ans << endl;
    }

    return 0;
}
