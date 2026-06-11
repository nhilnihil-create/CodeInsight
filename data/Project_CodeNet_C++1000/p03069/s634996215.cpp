#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll bdp[n+10],wdp[n+10];
    wdp[0]=0;
    bdp[0]=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='#'){
            bdp[i+1]=bdp[i]+1;
            wdp[i+1]=wdp[i];
        }
        else {
            bdp[i+1]=bdp[i];
            wdp[i+1]=wdp[i]+1;
        }
    }
    ll ans=MOD;
    ll num=wdp[n];
    for(ll i=0;i<=n;i++){
        ll x=bdp[i],y=num-wdp[i];
        ans=min(ans,x+y);
    }
    cout << ans << endl;
}