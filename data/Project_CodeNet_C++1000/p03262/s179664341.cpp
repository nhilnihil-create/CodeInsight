#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n;
    cin >> n;
    ve<int> a(n+1);
    rep(i,n+1) cin >> a[i];
    sort(a.begin(), a.end());
    ve<int> sa(n);
    rep(i,n) sa[i] = a[i+1]-a[i];
    int ans = sa[0];
    rep(i,n-1) ans = __gcd(ans,sa[i+1]);
    cout << ans << endl;
    return 0;
}