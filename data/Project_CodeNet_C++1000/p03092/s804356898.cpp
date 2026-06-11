#include <bits/stdc++.h>
#define fast        ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein      freopen("input.txt","r",stdin)
#define fileout     freopen("output.txt","w",stdout)
#define ll          long long
#define pii         pair<int,int>
using namespace std;

ll dp[5007][5007];
ll a,b,n;
ll arr[5007],pos[5007];

ll DP(int ind,int cur){
    if(dp[ind][cur]!=-1) return dp[ind][cur];

    if(ind==0) return dp[ind][cur]=0;

    if(pos[ind]>cur) {
        return dp[ind][cur] = DP(ind-1,cur)+b;
    }

    dp[ind][cur] = min(DP(ind-1,pos[ind]),DP(ind-1,cur)+a);
    return dp[ind][cur];
}

int main(){
    fast;
    memset(dp,-1,sizeof dp);

    cin>>n>>a>>b;

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        pos[arr[i]] = i;
    }

    cout<<DP(n,n)<<endl;

    return 0;
}
