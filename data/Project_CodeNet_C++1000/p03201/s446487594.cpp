#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int n;
    cin>>n;
    ll a[n];
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a,a+n,greater<ll>());
    int ans =0;
    for(int i=0;i<n;i++){
        ll p=2;
        if(mp[a[i]]==0) continue;
        while(p<2e9+3){
            if(p-a[i]>=1){
                if(p-a[i]==a[i]){
                    ans += mp[a[i]]/2;
                    break;
                }
                ans += min(mp[a[i]],mp[p-a[i]]);
                mp[p-a[i]] -= min(mp[a[i]],mp[p-a[i]]);
                break;
            }
            p*=2;
        }
        mp[a[i]] = 0;
    }
    cout << ans << endl;
}