#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[100001];
int solve(int arr[],int n,int k){
    if(k==0){
        return 0;
    }

    if(dp[k]!=-1)
        return dp[k];

    for(int i=1;i<=n;i++)
        if(k>=arr[i] && solve(arr,n,k-arr[i])==0)
            {
                dp[k] = 1;
                return 1;
            }   
    return dp[k] = 0;
}
int main()
{
    int n,k;
    cin>>n>>k;

    memset(dp,-1,sizeof dp);

    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    if(solve(arr,n,k))
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    
    return 0;
}