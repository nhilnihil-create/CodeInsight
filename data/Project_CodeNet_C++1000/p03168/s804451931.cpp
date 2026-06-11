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
ld dp[3005][3005];
void solve()
{
   ll n;
   cin>>n;
   ld pro[n+3];
   for(int i=1;i<=n;i++)
   { 
   	 cin>>pro[i];
   }
   dp[0][0]=1;
   for(int i=1;i<=n;i++)
   {
   	   dp[i][0]=(dp[i-1][0])*(1-pro[i]);
       for(int j=1;j<=i;j++)
       {
           dp[i][j]=dp[i-1][j]*(1-pro[i])+dp[i-1][j-1]*pro[i];
       }
   }
   ld ans=0;
   for(int i=n/2+1;i<=n;i++)
   {
   	  ans+=dp[n][i];
   }
   DEC(15);
   cout<<ans;
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