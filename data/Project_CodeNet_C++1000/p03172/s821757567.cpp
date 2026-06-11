/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  100005
ll dp[105][N];
void solve()
{
   ll n,k;
   cin>>n>>k;
   ll a[n+3];
   for(int i=1;i<=n;i++)
   {
    cin>>a[i];
   }
   dp[0][0]=1;
   for(int i=1;i<=a[1];i++)
      dp[1][i]=1;
    dp[1][0]=1;
   for(int i=2;i<=n;i++)
   {   
       for(int j=1;j<=k;j++)
       {
          dp[i-1][j]=(dp[i-1][j]+dp[i-1][j-1])%hell;
       }
       for(int j=0;j<=k;j++)
       {
           if(j-a[i]-1<0)
              dp[i][j]=(dp[i-1][j])%hell;
           else
              dp[i][j]=(dp[i-1][j]-dp[i-1][j-a[i]-1]+hell)%hell;
       }
   }
  // cout<<dp[1][8]-dp[1][3];
   cout<<dp[n][k]<<endl;
   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}