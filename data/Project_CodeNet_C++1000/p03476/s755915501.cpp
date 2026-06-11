#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

bool prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    vector<ll>data(1e5+10,0);
    for(ll i=1;i<1e5+10;i+=2){
        if(prime(i)&&prime((i+1)/2)){
            data[i]++;
        }
    }
    for(ll i=1;i<1e5+10;i++){
        data[i]+=data[i-1];
    }
    ll q;
    cin >> q;
    for(ll i=0;i<q;i++){
        ll l,r;
        cin >> l >> r;
        ll ans=data[r]-data[l-1];
        cout << ans << endl;
    }
}