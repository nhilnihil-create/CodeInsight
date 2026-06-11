#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
using G=vector<vector<int>>;
#define INF 10000000000000ll
int a,b,q;
vector<ll> s(100005),t(100005);
P sBS(ll x){
    int l=0,r=a-1;
    P p;
    if(s.at(0)>x){
        p.first=-INF;
        p.second=s.at(0);
        return p;
    }
    if(s.at(a-1)<x){
        p.first=s.at(a-1);
        p.second=INF;
        return p;
    }
    while(r-l>1){
        if(s.at((l+r)/2)>x) r=(l+r)/2;
        if(s.at((l+r)/2)<x) l=(l+r)/2;
    }
    
    p=make_pair(s.at(l),s.at(r));
    return p;
}
P tBS(ll x){
    int l=0,r=b-1;
    P p;
    if(t.at(0)>x){
        p.first=-INF;
        p.second=t.at(0);
        return p;
    }
    if(t.at(b-1)<x){
        p.first=t.at(b-1);
        p.second=INF;
        return p;
    }
    while(r-l>1){
        if(t.at((l+r)/2)>x) r=(l+r)/2;
        if(t.at((l+r)/2)<x) l=(l+r)/2;
        
    }
    p=make_pair(t.at(l),t.at(r));
    return p;
}
int main(){
    
    cin >> a >> b >> q;
    
    rp(i,a) cin >> s.at(i);
    rp(i,b) cin >> t.at(i);
    vector<ll>  ans(q);
    rp(i,q){
        ll x;
        cin >> x;
        ll cand;
        cand=x-tBS(sBS(x).first).first;
        cand=min(cand,tBS(sBS(x).second).second-x);
        cand=min(cand,(x-sBS(x).first)+(tBS(sBS(x).first).second-sBS(x).first));
        cand=min(cand,(sBS(x).second-x)+(sBS(x).second-tBS(sBS(x).second).first));
        cand=min(cand,x-sBS(tBS(x).first).first);
        cand=min(cand,sBS(tBS(x).second).second-x);
        cand=min(cand,(x-tBS(x).first)+(sBS(tBS(x).first).second-tBS(x).first));
        cand=min(cand,(tBS(x).second-x)+(tBS(x).second-sBS(tBS(x).second).first));
        ans.at(i)=cand;
    }
    for(auto an:ans){
        cout << an << endl;
    }
    return 0;
}