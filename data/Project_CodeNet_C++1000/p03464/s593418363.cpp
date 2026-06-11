#include <bits/stdc++.h>
using ll = long;
using namespace std;

int main(){
    ll k, d=2, u=2; cin >> k;
    ll a[k]; for(ll i =0 ; i < k; i++) cin >> a[i];
    for(ll i = k-1; i >= 0; i--){
        d = (d+a[i]-1)/a[i]; u = u/a[i];
        if(d > u){ cout << -1 << endl; return 0; }
        d *= a[i]; u *= a[i]; u += a[i]-1;
    }
    cout << d << " " << u << endl;
}