#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll dp[200010];

int main(){
    ll n;cin>>n;
    vector<ll> coin;
    coin.push_back(1LL);
    rep(i,1,7)coin.push_back((ll)pow(6,i));
    rep(i,1,6)coin.push_back((ll)pow(9,i));
    rep(i,0,n+1)dp[i]=1e9;
    dp[0]=0;
    rep(i,0,n+1){
        rep(j,0,coin.size()){
            dp[i+coin[j]]=min(dp[i+coin[j]],dp[i]+1);
        }
    }
    cout<<dp[n]<<endl;
}

    







