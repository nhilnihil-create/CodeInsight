#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> a(n + 2, 0);
    ll sum = 0;
    for(int i = 1; i < n + 1; i++){
        cin >> a[i];
        sum += abs(a[i] - a[i - 1]);
    }
    sum += abs(a[n]);
    for(int i = 1; i < n + 1; i++){
        ll x = abs(a[i] - a[i - 1]);
        ll y = abs(a[i + 1] - a[i]);
        ll z = abs(a[i - 1] - a[i + 1]);
        ll ans = sum - (x + y) + z;
        cout << ans << endl;
    }
}
