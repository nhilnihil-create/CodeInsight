#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    vector<ll> sum(n+1);
    rep(i, n){
        sum[i+1] = sum[i]+v[i]; 
    }
    map<ll, ll> mp;
    rep(i, n+1){
        mp[sum[i]]++;
    }
    //rep(i, n+1) cout<<sum[i]<<endl;
    ll ans = 0;
    for(auto p : mp){
        ans += p.second*(p.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}