#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int N;cin>>N;
    vector<int> h(N);
    rep(i,N) cin>>h[i];

    vector<int> dp(N+1);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    
    for(int i=2;i<=N;i++){
            dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<dp[N-1]<<endl;
}