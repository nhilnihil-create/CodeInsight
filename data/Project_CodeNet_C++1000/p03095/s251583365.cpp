#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n;
    string s;
    cin>>n>>s;
    map<char,ll> mp;
    rep(i,n) mp[s[i]]++;
    ll ans=1;
    for(auto x:mp) ans *= (x.second+1)%mod,ans%=mod;
    cout<<(ans-1)%mod<<endl;
    return 0;
}