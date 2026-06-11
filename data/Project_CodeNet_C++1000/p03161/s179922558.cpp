//invincible M15
//IIT-(ISM)Dhanbad
#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define pi  3.141592653589793238462643383279
#define ff first
#define ss second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=(int)x; i<y; i++)
#define high_functioning_sociopath  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const unsigned int M = 1000000007;
/*------------------------------------- THE GAME IS ON ---------------------------------------------*/
ll dp[100005];
ll mincost(int n,int arr[],int k)
{
       if(n<=k)return (abs(arr[n-1]-arr[0]));
       if(dp[n]!=-1)return dp[n];
       else
       {
              ll minn=INT_MAX;
              for(int i=1;i<=k;i++)
              {
                      minn=min(minn,(abs(arr[n-1]-arr[n-(i+1)])+mincost(n-i,arr,k)));
              }
              return dp[n]=minn;
       }
}
void solve()
{
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i=0;i<n;i++)cin>>arr[i];
       memset(dp,-1,sizeof(dp));
       cout<<mincost(n,arr,k)<<endl;
}
int32_t main()
{
   high_functioning_sociopath
   ll t=1;
   //cin>>t;
   while(t--)
   {
      solve();
   }
}