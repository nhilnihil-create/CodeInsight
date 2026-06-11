#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> k;
    vector<ll> a(k);
    for(ll i = 0; i < k; i++) {
        cin >> a[i];
    }

    ll mn=2;
    ll mx=2;
    for(ll i = 0; i < k; i++) {
        ll m=a[k-1-i];
        if(mx/m-(mn-1)/m<=0){
            cout << "-1" << "\n";
            return 0;
        }
        mn=m*((mn+m-1)/m);
        mx=m*(mx/m)+m-1;
    }
    cout << mn << " " << mx << "\n";

    return 0;
}