#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(auto i=a;i<n;i+=x)
#define forD(i,a,n,x) for(auto i=n-1;i>=0;i-=x)
#define ranit(it,n) for(auto it:n)
#define testCases ll t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

ld c[3003]; ld dp[3003][3003];

ld solve(ll n , ll heads , ll tails)
{
	if(n==0)
	{
		if(heads>tails)return 1.0;
		else return 0.0;
	}

	if(dp[n][heads]!=-1) return dp[n][heads];
	ld hp = c[n-1];  ld tp = 1.0-hp; 

	return dp[n][heads]= hp*solve(n-1,heads+1,tails) + tp*solve(n-1,heads,tails+1);
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	ll n; cin>>n; forA(i,0,n,1)cin>>c[i];
	forA(i,0,3003,1)forA(j,0,3003,1) dp[i][j]=-1;
	ld ans = solve(n,0,0);
	cout<<fixed<<setprecision(10)<<ans<<"\n";
	return 0;
}