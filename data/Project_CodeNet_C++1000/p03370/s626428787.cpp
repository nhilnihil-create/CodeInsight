#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll n,x;
cin >> n >> x;
ll m[n];
for (ll i = 0; i < n; i++) cin >> m[i];
sort(m, m + n);
for (ll i = 0;i<n;i++){
    x -= m[i];
}
ll ans = n + x / m[0];
cout << ans << endl;
}
