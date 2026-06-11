#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double EPS=1e-9;
const int MOD=1e9+7;
int main(){
    int h,w;cin>>h>>w;swap(h,w);
    int n;cin>>n;
    if(n==0){
        cout<<w<<endl;
        return 0;
    }
    vector<pair<P,int>> v;
    map<P,int> mp;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;x--;y--;
        mp[P(x+1,y)]++;
        mp[P(x-1,y)]++;
        mp[P(x,y-1)]++;
        v.push_back(make_pair(P(y,x),0));
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        P p=itr->first;
        if(itr->second>=3&&p.first>=0&&p.second>=0){
            v.push_back(make_pair(P(p.second,p.first),1));
        }
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    ll ans=w;
    int co=0;
    for(int i=0;i<n;i++){
        ll y=v[i].first.first,x=v[i].first.second;
        if(x<y+co)continue;
        if(x==y+co){
            co++;continue;
        }
        if(v[i].second){
            ans=min(ans,x);
            continue;
        }
        ans=min(ans,x);
    }
    cout<<ans<<endl;
}
