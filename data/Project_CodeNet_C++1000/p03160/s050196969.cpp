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
ll mincost(int n,int arr[])
{
       if(n==2)return dp[n]=(abs(arr[1]-arr[0]));
       if(n==1)return 0;
       if(dp[n]!=-1)return dp[n];
       else return dp[n]=min((abs(arr[n-1]-arr[n-2]))+mincost(n-1,arr),(abs(arr[n-1]-arr[n-3]))+mincost(n-2,arr));
}
void solve()
{
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)cin>>arr[i];
       memset(dp,-1,sizeof(dp));
       cout<<mincost(n,arr)<<endl;
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