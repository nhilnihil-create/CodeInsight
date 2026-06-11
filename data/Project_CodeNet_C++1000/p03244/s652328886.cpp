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
    int n;cin>>n;
    map<int,int>mp1,mp2;
    for(int i=0,x;i<n;++i){
        cin>>x;
        if(i%2){
            mp1[x]++;
        }
        else
            mp2[x]++;
    }
    vector<pair<int,int>>vp1,vp2;
    for(auto x:mp1){
        vp1.emplace_back(x.second,x.first);
    }
    for(auto x:mp2){
        vp2.emplace_back(x.second,x.first);
    }
    sort(all(vp1),greater<pair<int,int>>());
    sort(all(vp2),greater<pair<int,int>>());
    if(vp1[0].second==vp2[0].second){
        int cnt1=vp1[0].first;
        if(int(vp2.size())>1)
            cnt1+=vp2[1].first;
        int cnt2=vp2[0].first;
        if(int(vp1.size())>1)
            cnt2+=vp1[1].first;
        cout<<n-max(cnt1,cnt2);
    }
    else{
        cout<<n-vp1[0].first-vp2[0].first;
    }
}