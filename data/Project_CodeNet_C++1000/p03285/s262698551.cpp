#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n;
    cin>>n;
    bool dp[110];
    rep(i,110) dp[i]=false;
    dp[0]=true;
    rep(i,100){
        if(i+4<=100) dp[i+4]=dp[i+4] || dp[i];
        if(i+7<=100) dp[i+7]=dp[i+7] || dp[i];
    }
    //rep(i,101) cout<<i<<" "<<dp[i]<<endl;
    if(dp[n]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}