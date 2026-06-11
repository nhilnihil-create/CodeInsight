#include <bits/stdc++.h>
//#define int long long 

using namespace std;
int dp[1000001][3];
int arr[10000001][3];
int solve(int n,int i)
{
    if(n < 0 )
        return 0;
    if(dp[n][i]!=-1)
        return dp[n][i];
    return dp[n][i]=max(arr[n][i%3]+solve(n-1,(i+1)%3),arr[n][i%3]+solve(n-1,(i+2)%3));
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }
    int mx = max(solve(n-1,0),max(solve(n-1,1),solve(n-1,2)));
    cout<<mx<<endl;


}