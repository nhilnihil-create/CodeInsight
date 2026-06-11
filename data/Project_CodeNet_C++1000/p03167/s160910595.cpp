#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;

ll dp[1005][1005];
string a[1000+5];
ll mod=1e9+7,n,m;
ll solve(ll i,ll j)
{
    if(i==n-1 && j==m-1)return 1;
    if(i>=n ||i<0 || j>=m || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j]%mod;
    dp[i][j]=0;
    if(i+1<n)if(a[i+1][j]!='#')dp[i][j]=(solve(i+1,j))%mod;
    if(j+1<m)if(a[i][j+1]!='#')dp[i][j]=(dp[i][j]%mod+solve(i,j+1)%mod)%mod;

    return dp[i][j]%mod;

}



int main()
{

    memset(dp,-1,sizeof dp);
    cin>>n>>m;



    fr(i,0,n)cin>>a[i];

    cout<<solve(0,0)<<endl;










}


























