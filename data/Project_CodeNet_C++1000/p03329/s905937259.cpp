#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll ans=n;
    for(ll i=0;i<=n;i++){
        ll x=0,t=i;
        while(t>0){
            x+=t%6;
            t/=6;
        }
        t=n-i;
        while(t>0){
            x+=t%9;
            t/=9;
        }
        ans=min(ans,x);
    }
    cout << ans << endl;
}
