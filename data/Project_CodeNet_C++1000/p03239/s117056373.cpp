#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,srt,end) for( ll i=(ll)(srt); i<(ll)(end); i++ )
#define VL vector<ll>
#define INF 1e18

int main(){
    ll N,T;
    cin>>N>>T;
    VL c(N),t(N);
    rep(i,0,N)cin>>c[i]>>t[i];
    
    ll ans=INF;
    rep(i,0,N){
        if(T>=t[i])ans=min(ans,c[i]);
    }
    if(ans==INF)cout<<"TLE"<<endl;
    else cout<<ans<<endl;
    
    return 0;
}