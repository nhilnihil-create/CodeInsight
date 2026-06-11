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
ll dp[405][405];
ll pre[405];
ll fun(ll l,ll r)
{
   if(dp[l][r]!=1e18)
      return dp[l][r];
    if(l==r)
      return 0;
    for(int i=l;i<r;i++)
    {
        dp[l][r]=min(dp[l][r],fun(l,i)+fun(i+1,r)+pre[r]-pre[l-1]);
    }
    return dp[l][r];
}
void solve()
{
   ll n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
        dp[i][j]=1e18;
   }
   for(int i=1;i<=n;i++)
   {
       ll x;
       cin>>x;
       pre[i]=pre[i-1]+x;
   }
   cout<<fun(1,n);
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