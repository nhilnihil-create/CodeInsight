#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map<ll,ll> mp;
ll ask(ll n){
    if(mp.count(n))return mp[n];

    cout<<n<<endl;
    string s;cin>>s;
    if(s=="Vacant")exit(0);
    return mp[n]=(s=="Male");
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    ll s=0,e=n-1;
    while(e-s>=2){
        ll m=(s+e)>>1;
        if( (ask(m)^(m%2)) != (ask(s)^(s%2)) )e=m;
        else s=m;
    }
    for(ll i=s;i<=e;i++)ask(i);
}