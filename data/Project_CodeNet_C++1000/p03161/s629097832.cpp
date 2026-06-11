#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N];
int dp[N];
int n,K;

int func(int index){
    if(index==n-1){
        return 0;
    }
    if(dp[index]!=-1)   return dp[index];
    int ans=2e9;
    for(int k=1;k<=K && index+k<n;k++){
        ans=min(ans,abs(a[index]-a[index+k])+func(index+k));
    }
    return dp[index]=ans;
}
main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>K;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)    cin>>a[i];
    cout<<func(0)<<"\n";
}