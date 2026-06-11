#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N);
    ll ans = 10000000000000001;

    for (ll i = 0; i < N; i++) cin >> x[i];

    for (ll l = 0; l < N-K+1; l++) {
        ll r = l+K-1;
        ll cost1, cost2;
        cost1 = abs(x[l]) + abs(x[r]-x[l]);
        cost2 = abs(x[r]) + abs(x[r]-x[l]);
        ans = min(ans, min(cost1, cost2));
    }
 
    cout << ans << endl;
}