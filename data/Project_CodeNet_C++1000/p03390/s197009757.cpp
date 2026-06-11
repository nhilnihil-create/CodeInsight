#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b; if(a < b) swap(a,b); // a >= b
        if(a-b == 0) cout << 2*(b-1) << endl;
        else if(a-b == 1) cout << 2*(b-1) << endl;
        else{
            ll k = (ll)sqrt(a*b);
            if(k*k == a*b) cout << 2*k-3 << endl;
            else if(k*(k+1) < a*b) cout << 2*k-1 << endl;
            else cout << 2*k-2 << endl;
        }
    }
}