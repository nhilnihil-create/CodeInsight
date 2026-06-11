#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n, k; cin >> n >> k;
    V<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    ll ans = INF;
    for(int l = 0; l <= n - k; l++){
        ll r = l + k - 1;
        ans = min(ans, abs(x[l]) + abs(x[l] - x[r]));
        ans = min(ans, abs(x[r]) + abs(x[l] - x[r]));
    }
    cout << ans << endl;

}
