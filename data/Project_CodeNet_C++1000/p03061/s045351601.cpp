#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 5e5 + 2;
ll GCD(ll x, ll y) {
    return (!y) ? x : GCD(y, x % y);
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int a[n], gcd[n], gcd2[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) gcd[i] = a[i];
        else gcd[i] = GCD(gcd[i - 1], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1)  gcd2[i] = a[i];
        else gcd2[i] = GCD(gcd2[i + 1], a[i]);
    }
    ll ans = max(gcd[n - 2], gcd2[1]);
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, GCD(gcd[i - 1], gcd2[i + 1]));
    }
    cout << ans;
    return 0;
}