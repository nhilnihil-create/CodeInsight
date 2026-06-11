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
ll dp[100005][4];
vi a(100005),b(100005),c(100005);
ll n;
ll solve(ll taken,ll i,ll j)
{
    if(i>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    if(taken!=1) dp[i][1]=a[i]+max(solve(1,i+1,2),solve(1,i+1,3));
    if(taken!=2)dp[i][2]=b[i]+max(solve(2,i+1,1),solve(2,i+1,3));
    if(taken!=3)dp[i][3]=c[i]+max(solve(3,i+1,1),solve(3,i+1,2));

    if(taken==1)return max({dp[i][2],dp[i][3]});
    if(taken==2)return max({dp[i][1],dp[i][3]});
    if(taken==3)return max({dp[i][2],dp[i][1]});
    else return max({dp[i][2],dp[i][1],dp[i][3]});
}



int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    fr(i,0,n)cin>>a[i]>>b[i]>>c[i];

    cout<<solve(0,0,0)<<endl;


   /* fr(i,1,4)
    {
        fr(j,0,n)cout<<dp[j][i]<<" ";
        cout<<endl;
    }
*/

}

























