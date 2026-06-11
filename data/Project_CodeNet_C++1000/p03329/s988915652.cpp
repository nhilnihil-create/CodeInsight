#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int dp[100010];

int main(){
    int n;
    cin>>n;
    rep(i,100010) dp[i]=INF;
    dp[0]=0;
    rep(i,100010){
        dp[i+1]=min(dp[i+1],dp[i]+1);
        for(int j=1;j<100;j++){
            if(i+pow(6,j)>100000) break;
            int x=pow(6,j);
            dp[i+x]=min(dp[i+x],dp[i]+1);
        }
        for(int j=1;j<100;j++){
            if(i+pow(9,j)>100000) break;
            int x=pow(9,j);
            dp[i+x]=min(dp[i+x],dp[i]+1);
        }

    }

    //rep(i,n+1) cout<<i<<" "<<dp[i]<<endl;
    cout<<dp[n]<<endl;
}