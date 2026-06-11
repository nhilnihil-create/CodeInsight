#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
int n;
ll mod= 1e9+7;
ll dp[21][(1<<21)];
ll solve(int i,int state,vector<vector<int> > &arr)
{
    if(i==n)
    {
        return 1;
    }
    if(dp[i][state]!=-1)
    return dp[i][state];
    dp[i][state]=0;
    for(int j=0;j<n;j++)
    {
       if((state>>j)&1 && arr[i][j]==1)
        {
            dp[i][state]+=solve(i+1,(state^(1<<j)),arr);
            dp[i][state]%=mod;
        }
    }
    return dp[i][state];
}
int main()
{
    cin>>n;
    vector<vector<int>> arr(n,(vector<int>(n,0)));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<1<<21;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<(solve(0,(1<<n)-1,arr))%mod;

}