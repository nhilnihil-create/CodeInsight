#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,M;
    cin>>N>>M;
    vector<LP> AB(N);
    rep(i,N){
        cin>>AB.at(i).first>>AB.at(i).second;
    }
    sort(AB.begin(),AB.end());
    ll ans=0;
    int now=0;
    int po=0;
    while(po<N && now+AB.at(po).second<=M){
        ans+=AB.at(po).first*AB.at(po).second;
        now+=AB.at(po).second;
        po++;
    }
    if(now<M)ans+=AB.at(po).first*(M-now);
    cout<<ans<<endl;
}