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
    ll n,cnt=0; cin>>n;
    vector<ll> s(n+1,0);
    map<ll,ll> mp;
    rep(i,n){
        ll a; cin>>a;
        s[i+1]=s[i]+a;
    }
    rep(i,n+1) mp[s[i]]++;
    for(auto x:mp) cnt += x.second*(x.second-1)/2;
    cout<<cnt<<endl;
    return 0;
}