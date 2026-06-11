#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    ll ans=1;
    for(ll i=1;i*i<=m;i++){
        if(m%i==0&&i*n<=m){
            ans=max(ans,i);

            ll x=m/i;
            if(x*n<=m){
                ans=max(ans,x);
            }
        }
    }
    cout << ans << endl;
}
