#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
long long GCD(long long n, long long m) {
    return m ? GCD(m, n % m) : n;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll g = GCD(n, m);
    bool ok = true;
    ll ans = n*m/g;
    for(ll i = 0; i < g; ++i) {
        if(s[i*n/g]!=t[i*m/g]) ok = false;
    }
    if(ok) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}