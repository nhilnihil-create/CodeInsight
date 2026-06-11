#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll f[100][14];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<10;j++){
            cin >> f[i][j];
        }
    }
    ll p[100][15];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<11;j++){
            cin >> p[i][j];
        }
    }
    ll ans=-1e10;
    for(ll tmp=1;tmp<(1<<10);tmp++){
        ll x=0;
        for(ll i=0;i<n;i++){
            ll y=0;
            for(ll j=0;j<10;j++){
                if((tmp>>j&1)&&f[i][j]==1)y++;
            }
            x+=p[i][y];
        }
        ans=max(ans,x);
    }
    cout << ans << endl;
}