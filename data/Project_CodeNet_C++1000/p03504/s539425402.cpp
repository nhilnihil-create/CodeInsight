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
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,C;
vector<P> st[35];
ll emos[100010]={};
int main(){
    cin>>N>>C;
    for(ll i=0;i<N;i++){
        ll s,t,c;
        cin>>s>>t>>c;
        st[c].push_back(P(s,t));
    }
    for(ll i=1;i<=C;i++){
        sort(st[i].begin(),st[i].end());
        ll pre=-1;
        for(auto s:st[i]){
            if(pre==s.first){
                s.first++;
            }
            emos[s.first]++;
            emos[s.second+1]--;
            pre=s.second;
        }
    }
    ll ans=0;
    for(ll i=1;i<100010;i++){
        emos[i]+=emos[i-1];
        ans=max(ans,emos[i]);
    }
    cout<<ans<<endl;
    return 0;
}