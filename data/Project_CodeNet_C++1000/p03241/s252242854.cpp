#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    ll ans = 1;
    for(ll i = 1; i*i <= m; i++){
        if(m % i == 0){
            ll tmp = m/i;
            if(tmp >= n) ans = max(ans, i);
            if(i >= n) ans = max(ans, tmp);
        }
    }
    if(n == 1) ans = m;
    cout << ans << endl;
}
