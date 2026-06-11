#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    vector<ll> ans1(x*y);
    rep(i,x) rep(j,y) ans1[i*y+j] = a[i] + b[j];
    sort(all(ans1), greater<ll>());

    ll s = min(3000ll, x*y);
    vector<ll> ans2(s);
    rep(i,s) ans2[i] = ans1[i];

    sort(all(c),greater<ll>());

    vector<ll> ans3(s*z);
    rep(i,s) rep(j,z) ans3[i*z+j] = ans2[i] + c[j];
    sort(all(ans3), greater<ll>());

    rep(i,k) cout << ans3[i] << endl;
}