#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(NULL); 
#define fi first
#define se second
#define mp make_pair
#define pi 3.14159265359
#define MOD 1000000007
typedef long long ll;
#define mp make_pair
#define ALL(v) v.begin(), v.end() 
#define F(i,s,n) for(i=s;i<n;++i)
#define pb push_back
#define tin freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
ll max(ll a,ll b)
{
    return a*(a>=b)+b*(b>a);
}
/*----------------------------------------------------------*/

void solve()
{
	ll n;cin>>n;vector<ll>a(n),dp(n);
  	for(auto &i:a)cin>>i;
  	if(n==1){cout<<"0";return;}
  	dp[0]=0;dp[1]=abs(a[1]-a[0]);
  	for(ll i=2;i<n;++i)
    {
      dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
  cout<<dp[n-1];
}

int main()
{
    //tin
    fast
    ll tc=1;//cin>>tc;
   for(ll i=1;i<=tc;++i)
   {
    //cout<<"Case #"<<i<<": ";
    solve();
    if(i!=tc)cout<<"\n";
   }
return 0;
}
//End-Cases
//Precomputation
//Segmentation Fault
//Complexity
//Break it up
//Sub Problems
