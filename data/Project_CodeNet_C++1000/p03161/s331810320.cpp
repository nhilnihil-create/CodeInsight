#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int N,K;cin>>N>>K;
    vector<ll> h(100010);
    rep(i,N) cin>>h[i];

    vector<ll> dp(100010,M);
    dp[0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=1;j<=K;j++){
            dp[i+j]=min(dp[i+j],dp[i]+abs(h[i+j]-h[i]));
        }
    }
    cout<<dp[N-1]<<endl;
}