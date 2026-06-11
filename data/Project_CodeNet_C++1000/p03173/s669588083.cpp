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
#define mod         10000000000007
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
ll a[405], dp[405][405], n;
ll sum(ll i, ll j)
{
	ll d=0;
	repi(k,i,j) d+=a[k];
	return d;
}
ll cc(ll s, ll e)
{
	if(s==e) dp[s][e] = 0;
	if(s>e) return mod;
	if(dp[s][e] != -1 )return dp[s][e];
	ll ans = mod, x, cost;
	
	repi(i,s,e-1)
	{
		ans = min(ans, cc(s,i) + cc(i+1,e) + sum(s,e));
	}
	return dp[s][e]=ans;
}
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
    	cin>>n;
    	rep(i,0,n) cin>>a[i];
    	repi(i,0,n){
    		repi(j,0,n) dp[i][j]=-1;
		}
    	cout<<cc(0,n-1);
	}
	return 0;
}