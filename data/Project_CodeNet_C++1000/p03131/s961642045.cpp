#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll k, a, b;
    cin >> k >> a >> b;
    ll ap = k+1;
    ll c = k-(a-1), d = b - a;
    ll e = c/2*d, f = c%2;
    ll ans = 0;
    if(f == 1) ans = e-d + b + 1;
    else ans = e-d + b;
    if(ap > ans) cout << ap << endl;
    else cout << ans << endl;
    return 0;
}