#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    for(ll i = 1; i*i<=m; ++i) {
        if(m%i!=0) continue;
        ll x = m/i;
        if(i*n <= m) ans = max(ans, i);
        if(x*n <= m) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}   