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
ll dp[3005][3005];
void solve()
{
   dp[0][0]=0;
   string a,b;
   cin>>a>>b;
   ll n=a.size(),m=b.size();
   a="*"+a;
   b="*"+b;
   for(int i=1;i<=n;i++)
   {
   	  for(int j=1;j<=m;j++)
   	  {
   	  	  dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
   	  	  if(a[i]==b[j])
   	  	  {
   	  	  	  dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
   	  	  }
   	  }
   }
   ll i=n,j=m;
   std::vector<char> v;
   while(i>0&&j>0)
   {
   	  if(a[i]==b[j]&&dp[i][j]==dp[i-1][j-1]+1)
   	  {
          v.pb(a[i]);
   	  	  i--;
   	  	  j--;
   	  }
   	  else
   	  {
   	  	  if(dp[i-1][j]==dp[i][j])
   	  	  {
   	  	  	  i--;
   	  	  }
   	  	  else
   	  	  	 j--;
   	  }
   }
   for(int i=0;i<v.size();i++)
   {
   	  cout<<v[v.size()-1-i];
   }

  // cout<<dp[n][m];
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