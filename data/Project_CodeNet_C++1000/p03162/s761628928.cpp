#include<iostream>
#include<climits>
using namespace std;
int dp[1000001][4];
int  a[1000001];
int  b[1000001];
int  c[1000001];

int solve(int n)
{
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    dp[1][2]=c[1];

    for(int i=2;i<=n;i++)
    {
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][1],dp[i-1][0]);
    }
    int c=max(dp[n][0],max(dp[n][1],dp[n][2]));
    return c;

}
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
    }
    cout<<solve(n)<<endl;
}