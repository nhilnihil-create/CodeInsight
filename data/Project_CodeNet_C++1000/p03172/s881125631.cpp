#include<bits/stdc++.h>
#define ll          long long int
#define lld          long double
#define pb          push_back
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define vec         vector<ll>
#define all(a)     (a).begin(),(a).end()
#define F           first
#define S           second
#define mod         1000000007
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define repi(i,a,b)	for(ll  i=a;i<=b;i++)
#define per(i,a,b)  for(ll i=a;i>=b;i--)
#define mp          make_pair
#define mit         map<ll,ll>::iterator
#define sit         set<ll>::iterator
#define xxx         exit(0);
#define pit         pair<ll,ll>::iterator
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
ll a[3005],dp[105][100005],p[105][100005]; ll n;
//ll E(ll s, ll k)
//{
//	if(k==0) return 1;
//	if((k>0 || k<0) && s==-1) return 0;
//	if(dp[s][k] != -1) return dp[s][k];
//	ll ans = 0;
//	repi(i,0,min(k,a[s])) ans = ( ans + E(s-1,k-i) )%mod;
//	return dp[s][k] = ans;
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
    while(TESTS--)
    {
    	ll i,j,k,l,m,h,w,val,K;
    	cin>>n>>K;
    	repi(i,1,n) cin>>a[i];
		repi(i,0,n) dp[i][0]=p[i][0]=1;
		repi(i,0,K) dp[0][i]=p[0][i]=1;
		repi(i,1,n)
		{
			repi(j,1,K)
			{
				w = (j-a[i]-1)>=0 ? p[i-1][j-a[i]-1] : 0;
				dp[i][j] = ( dp[i][j] + (p[i-1][j] - w + mod)%mod)%mod;
				p[i][j] = (p[i][j-1] + dp[i][j])%mod;
			}
		}
		cout<<dp[n][K];
	}
	return 0;
}