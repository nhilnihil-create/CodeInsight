#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,dp[100009][2],x,y;
vector<vector<ll> >v;
const ll mod=1e9+7;
ll best(ll d,ll p,bool b)
{
    ll &r=dp[d][b];
    if(r!=-1)return r;
    r=1;
    for(auto z:v[d])
    if(z!=p){

        if(b)
        r=(r*(best(z,d,0)+best(z,d,1)))%mod;
        else
        r=(r*best(z,d,1))%mod;
    }
    return r;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
v.resize(n+1);
for(ll i=1;i<n;i++){
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
}
memset(dp,-1,sizeof dp);
cout<<(best(1,0,0)+best(1,0,1))%mod;
return 0;
}
