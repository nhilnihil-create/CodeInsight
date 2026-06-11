#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll a,b,k; cin>>a>>b>>k;
    map<ll,ll> mp;
    for(int i=a;i<a+k;i++) mp[i]++;
    for(int i=b;i+k>b;i--) mp[i]++;
    for(auto x:mp){
        if(x.second){
            if(a<=x.first && x.first<=b) cout<<x.first<<endl;
        }
    }
    return 0;
}