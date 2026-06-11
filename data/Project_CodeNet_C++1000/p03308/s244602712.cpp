#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll n;
cin>>n;
ll a[n];
for (ll i = 0; i < n; i++) cin >> a[i];
sort(a, a + n);
cout << a[n - 1] - a[0] << endl;
}
