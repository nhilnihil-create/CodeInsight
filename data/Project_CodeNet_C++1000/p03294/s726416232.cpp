#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i] - 1;
    }
    cout << ans << endl;


    return 0;
}
