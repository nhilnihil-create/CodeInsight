#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=4e18;
const ll MOD=1e9+7;
const double EPS=1e-7;

ll N,K;
P xy[100];
int main(){
    cin>>N>>K;
    for(ll i=0;i<N;i++){
        ll x,y;
        cin>>x>>y;
        xy[i]=P(x,y);
    }
    sort(xy,xy+N);
    ll ans=INF;
    for(ll i=0;i<N;i++){
        for(ll j=N-1;j>=i+K-1;j--){
            vector<P> v;
            for(ll k=i;k<=j;k++){
                v.push_back(P(xy[k].second,xy[k].first));
            }
            ll w=xy[j].first-xy[i].first;
            sort(v.begin(),v.end());
            for(ll k=0;k<=v.size()-K;k++){
                ll h=v[k+K-1].first-v[k].first;
                ans=min(ans,h*w);
            }
        }
    }
    cout<<ans<<endl;
}