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
ll n,k;
ll a[105],dp[N];
ll fun(ll x)
{
    if(dp[x]!=-1)
        return dp[x];
    ll fl=0;
    for(int i=1;i<=n;i++)
    {
        if(x==a[i])
        {
          dp[x]=1;
          return dp[x];
        }        
    }
    for(int i=1;i<=n;i++)
    {
        if(x-a[i]<0)
          continue;
        if(!fun(x-a[i]))
        {
            dp[x]=1;
            return 1;
        }
    }
    dp[x]=0;
    return 0;

}
void solve()
{
   cin>>n>>k;
   memset(dp,-1,sizeof(dp));
   for(int i=1;i<=n;i++)
    cin>>a[i];
   if(fun(k))
    cout<<"First"<<endl;
   else
    cout<<"Second"<<endl;

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