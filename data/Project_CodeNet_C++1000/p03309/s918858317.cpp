#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n; cin >> n;

    V<ll> v(n);
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        v[i] = a - (i + 1);
    }
    sort(all(v));
    ll b = v[n / 2];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(v[i] - b);
    }
    cout << ans << endl;

}
