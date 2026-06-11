#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N][3];
int dp[N][4];
int n;
int func(int index,int last){
    if(index==n)    return 0;
    if(dp[index][last]!=-1)    return dp[index][last];

    int ans=0;
    for(int k=0;k<3;k++){
        if(k==last) continue;
        ans=max(ans,a[index][k]+func(index+1,k));
    }
    return dp[index][last]=ans;
}
main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout<<func(0,3)<<"\n";
}