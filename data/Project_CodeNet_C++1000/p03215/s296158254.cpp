#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll bit,ll k,vector<ll>v){
    if(bit==-1)return 0;
    vector<ll> tmp;
    for(ll i=0;i<(ll)v.size();i++)if((v[i]>>bit)&1)tmp.push_back(v[i]);
    if(tmp.size()>=k)return (1ll<<bit) + calc(bit-1,k,tmp);
    else return calc(bit-1,k,v);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;cin>>n>>k;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll> v;
    for(ll i=0;i<n;i++)for(ll j=i,sum=0;j<n;j++)sum+=a[j],v.push_back(sum);
    cout<< calc(60,k,v);
}

