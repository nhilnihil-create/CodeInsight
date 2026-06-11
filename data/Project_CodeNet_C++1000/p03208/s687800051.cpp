#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k; cin >> n >> k;
    V<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(ALL(h));

    ll ans = 1LL << 60;
    for(int i = 0; i < n - k + 1; i++){
        ans = min(ans, abs(h[i] - h[i + k - 1]));
    }
    cout << ans << endl;

    return 0;
}
