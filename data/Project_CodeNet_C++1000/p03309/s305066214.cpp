#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll n;
cin >> n;
ll a[n];
ll b[n];
for(ll i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i]-i;
}
sort(b,b+n);
ll best_b = b[n/2];
ll ans=0;
for(ll i=0;i<n;i++){
    ans+=abs(b[i]-best_b);
    }
    cout << ans << endl;
}
