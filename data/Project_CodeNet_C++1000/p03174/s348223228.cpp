#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define N 23
int n;
int ara[N][N];
ll dp[1<<23];
int Set(int n,int pos){
    return n | (1<<pos);
}
bool Check(int n,int pos){
    return (bool)(n & (1<<pos));
}
ll solve(int mask)
{
    if(mask==(1<<n)-1) return 1;
    if(dp[mask]!=-1) return dp[mask];
    dp[mask]=0;
    int j=0;
    for(int i=0;i<n;i++) if(Check(mask,i)) j++;
    for(int i=0;i<n;i++)
    {
        if(ara[i][j] && !Check(mask,i)) dp[mask]=(dp[mask]+solve(Set(mask,i)))%mod;
    }
    return dp[mask];
}
int main()
{
    fastio;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>ara[i][j];
    memset(dp,-1,sizeof dp);
    cout<<solve(0)<<endl;
}
