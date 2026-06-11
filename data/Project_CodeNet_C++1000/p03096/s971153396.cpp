#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    int n;
    cin>>n;
    vector<vector<int>>pos(200010);
    int col[200010];
    rep(i,n){
        
        cin>>col[i];
        pos[col[i]].push_back(i);
    }
    vector<long long> dp(200010,0);
    dp[0]=1;

    for(int i=0;i<n;i++){

        int color=col[i];
        dp[i+1]+=dp[i];

        int it=lower_bound(pos[color].begin(),pos[color].end(),i)-pos[color].begin();

        //if(it>=pos[color].size())continue;
        if(it>0){
            int p=pos[color][it-1];
            if(i-p>1){
            dp[i+1]+=dp[p+1];
            if(dp[i+1]>mod)dp[i+1]%=mod;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;

}
/*


*/
