#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define el endl
#define INF 1e8
typedef long long ll;
typedef long double ld;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll k = 1; k*k < n; k++){
        if(n % k == 0){
            ll m = (n/k) - 1LL;
            if(n/m == n%m) ans += m;
            if(k > 1){
                m = k - 1;
                if(n / m == n % m) ans += m;
            }
        }
    }
    cout << ans << endl;
}

