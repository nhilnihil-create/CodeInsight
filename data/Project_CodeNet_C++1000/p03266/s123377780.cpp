#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n, k; cin >> n >> k;
    V<ll> sum(k);
    for(int i = 1; i <= n; i++) sum[i % k]++;
    ll ans = 0;
    for(int a = 0; a < k; a++){
        ll b = (k - a) % k;
        ll c = (k - a) % k;
        if((b + c) % k != 0) continue;
        ans += sum[a] * sum[b] * sum[c];
    }
    cout << ans << endl;
}
