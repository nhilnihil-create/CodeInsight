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

bool f(P a,P b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    map<ll,ll>mp;
    vector<P>p(m);
    rep(i,m){
        ll d,y;
        cin>>d>>y;
        p[i].first=d;
        p[i].second=y;
        mp[i]=y;
    }
    sort(p.begin(),p.end(),f);
    map<ll,ll>ans;
    ll index=1,now;
    for(auto x:p){
        ll num;
        if(x.first!=now)index=1;
        now=x.first;
        num=x.first*pow(10,6)+index;
        ans[x.second]=num;
        index++;

    }
    rep(i,m){
        printf("%012lld\n",ans[mp[i]]);
    }
    return 0;
}