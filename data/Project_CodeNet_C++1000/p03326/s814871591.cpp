#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    ll a[n][3];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    ll ans=-1e18;
    for(ll bit=0;bit<(1<<3);bit++){
        vector<ll> vec;
        for(ll i=0;i<n;i++){
            ll s=0;
            for(ll j=0;j<3;j++){
                if(bit&(1<<j)) s+=a[i][j];
                else s-=a[i][j];
            }
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end(),greater<ll>());
        ll res=0;
        for(ll i=0;i<m;i++) res+=vec[i];
        ans=max(ans,res);
    }
    cout << ans << endl;
}
