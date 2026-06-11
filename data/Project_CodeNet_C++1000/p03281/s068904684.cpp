#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
bool ok(ll x){
    ll cnt=0;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            cnt+=2;
            if(i==x/i) cnt--;
        }
    }
    if(cnt==8){
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ll n;
    cin >> n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(i%2==0) continue;
        if(ok(i)) ans++;
    }
    cout << ans << endl;
}