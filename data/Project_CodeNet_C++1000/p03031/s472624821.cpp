#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>s(m);
    for(ll i=0;i<m;i++){
        ll k;
        cin >> k;
        for(ll j=0;j<k;j++){
            ll x;
            cin >> x;
            s[i].push_back(x-1);
        }
    }
    vector<ll>p(m);
    for(ll i=0;i<m;i++){
        cin >> p[i];
    }
    ll ans=0;
    for(ll i=0;i<(1<<n);i++){
        bool judge=true;
        for(ll j=0;j<m;j++){
            ll lamp=0;
            for(ll id:s[j]){
                if((i >> id) & 1){
                    lamp++;
                }
            }
            lamp%=2;
            if(lamp!=p[j]){
                judge=false;
            }
        }
        if(judge) ans++;
    }
    cout << ans << endl;
}