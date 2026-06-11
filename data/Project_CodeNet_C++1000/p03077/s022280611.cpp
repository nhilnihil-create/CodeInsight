#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n;
    vector<ll> a(5);
    cin >> n;
    rep(i, 5)cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 5 + (n-1)/a[0];
    cout << ans << endl;
    return 0;
}