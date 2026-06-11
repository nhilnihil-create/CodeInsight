#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<ll>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    if(k==1){
        //print the minimum dist from 0
        ll minm=INT_MAX;
        for(int i=0;i<n;++i){
            minm=min(abs(v[i]),minm);
        }
        return cout<<minm,0;
    }
    vector<int>dis;
    for(int i=0;i<int(v.size());++i){
        dis.emplace_back(v[i+1]-v[i]);
    }
    partial_sum(all(dis),dis.begin());
    ll minm=LLONG_MAX;
    for(int i=0;i+k-1<int(dis.size());++i){
        ll init=0;
        if(i!=0)init=dis[i-1];
        minm=min({minm,dis[i+k-2]-init+abs(v[i]),dis[i+k-2]-init+abs(v[i+k-1])});
       // D(minm);
    }
    cout<<minm;

    
}