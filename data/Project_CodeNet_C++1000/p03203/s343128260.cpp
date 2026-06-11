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
    vector<P> v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;x--;y--;
        v.push_back(P(y,x));
    }
    sort(all(v));
    ll ans=w;
    int co=0;
    for(int i=0;i<n;i++){
        ll y=v[i].first,x=v[i].second;
        if(x<y+co)continue;
        if(x==y+co){
            co++;continue;
        }
        ans=min(ans,x);
    }
    cout<<ans<<endl;
}
