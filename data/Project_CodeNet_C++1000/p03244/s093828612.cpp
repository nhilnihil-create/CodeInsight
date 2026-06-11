#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(ll i=ll(x);i<(ll)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<ll,ll>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    ll n;
    cin>>n;
    vector<lP>mp1(100005),mp2(100005);
    rep(i,n){
        ll v;
        cin>>v;
        if(i%2==0){
            mp1[v].first++;
            mp1[v].second=v;
        }
        else {
            mp2[v].first++;
            mp2[v].second=v;
        }
    }
    sort(mp1.begin(),mp1.end(),greater<P>());
    sort(mp2.begin(),mp2.end(),greater<P>());
    ll num;
    if(mp1[0].second==mp2[0].second){
        num=max(mp1[0].first+mp2[1].first,mp1[1].first+mp2[0].first);
    }
    else {
        num=mp1[0].first+mp2[0].first;
    }
    ll ans=n-num;
    cout<<ans<<endl;
    return 0;
}