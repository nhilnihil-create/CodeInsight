#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll dp[405][405];
ll solve(int i,int j,ll arr[]){
    if(j<=i)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];


    ll ans = 1e14;
    ll S =0;
    for(int k=i;k<=j;k++)
        S+=arr[k];

    for(int k=i;k<j;k++){

        // i to k, k+1 to j
        ans = min(ans,solve(i,k,arr)+solve(k+1,j,arr)+S);
    }

    return dp[i][j] = ans;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(0,n-1,arr);
    return 0;
}