#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,y,z,a,b,c,k,i,i1,w,ind,mini;
    cin>>x>>y>>z>>k;
    vector<ll>v1,v2,v3;
    for (i=0;i<x;i++){
        cin>>w;
        v1.push_back(w);
    }
    sort(v1.begin(),v1.end(),greater<ll>());
    for (i=0;i<y;i++){
        cin>>w;
        v2.push_back(w);
    }
    sort(v2.begin(),v2.end(),greater<ll>());
    for (i=0;i<z;i++){
        cin>>w;
        v3.push_back(w);
    }
    sort(v3.begin(),v3.end(),greater<ll>());
    a=0;
    b=0;
    c=0;
    set<pair<ll,pair<ll,ll> > >s;
    priority_queue<pair<ll,pair<ll,pair<ll,ll> > > >pq;
    pq.push({v1[0]+v2[0]+v3[0],{0,{0,0}}});
    for (i=0;i<k;i++){
        cout<<pq.top().first<<'\n';
        a=pq.top().second.first;
        b=pq.top().second.second.first;
        c=pq.top().second.second.second;
        //cout<<a<<' '<<b<<' '<<c<<'\n';
        pq.pop();
        if (a!=x-1&&s.find({a+1,{b,c}})==s.end()){
            s.insert({a+1,{b,c}});
            pq.push({v1[a+1]+v2[b]+v3[c],{a+1,{b,c}}});
        }
        if (b!=y-1&&s.find({a,{b+1,c}})==s.end()){
            s.insert({a,{b+1,c}});
            pq.push({v1[a]+v2[b+1]+v3[c],{a,{b+1,c}}});
        }
        if (c!=z-1&&s.find({a,{b,c+1}})==s.end()){
            s.insert({a,{b,c+1}});
            pq.push({v1[a]+v2[b]+v3[c+1],{a,{b,c+1}}});
        }
        
    }
}
