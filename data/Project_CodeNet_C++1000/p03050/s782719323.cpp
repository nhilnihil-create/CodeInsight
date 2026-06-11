#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// n = mk + k = k(m+1) k<m
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; ++i){
        if(n%i==0){
            ll x = n/i;
            x--;
            if(x > i) ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}