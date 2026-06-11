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
ll dp[1005][1005];
void solve()
{
   ll n,m;
   cin>>n>>m;
   char mat[n+3][m+3];
   for(int i=1;i<=n;i++)
   {
   	  for(int j=1;j<=m;j++)
   	  	cin>>mat[i][j];
   }
   dp[1][1]=1;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
       	   if(mat[i][j]=='#')
       	   	 dp[i][j]=0;
       	   	else
       	   	{
       	   		 if(!(i==1&&j==1))
       	   		 {
                       dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%hell;
                       dp[i][j]%=hell;
                       //cout<<dp[i][j]<<" ";
       	   		 }

       	   	}
       }
   }
   cout<<dp[n][m]<<endl;
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