#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    ll n, k;
    cin >> n >> k;

    if(k == 0){
        cout << n*n << endl;
        return 0;
    }
    ll ans = 0;
    for(ll i=k+1; i<=n; ++i){
        ans += (i-k) * (n/i);
        ll x = n % i;
        if(x - k >= 0 && k != 0){
            ans += x - k + 1;
        }
    }
    cout << ans << endl;

    return 0;
}