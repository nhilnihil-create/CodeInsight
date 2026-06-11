#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;

int main() {
    ll n, m; cin >> n >> m;

    ll ans = 1;
    for(ll i = 1; i * i <= m; i++){
        if(m % i != 0) continue;
        ll j = m / i;
        if(i * n <= m) ans = max(ans, i);
        if(j * n <= m) ans = max(ans, j);
    }
    cout << ans << endl;


    return 0;
}
