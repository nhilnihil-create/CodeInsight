#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        ll k = (ll)sqrt(a*b);
        if(k*k == a*b) cout << 2*k-3+(a==b?1:0) << endl;
        else if(k*(k+1) < a*b) cout << 2*k-1 << endl;
        else cout << 2*k-2 << endl;
    }
}