#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ans;
vector<ll> v;
map<ll,ll> mp;
ll f(ll n){
    ll m=1;
    while(m<=n)m*=2;
    return m-n;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        mp[a]++;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(mp[v[i]]>0)mp[v[i]]--;
        else continue;
        if(mp[f(v[i])]>0){
            mp[f(v[i])]--;
            ans++;
        }
    }
    cout<<ans<<endl;
}
