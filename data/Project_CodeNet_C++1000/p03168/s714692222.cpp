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

ld c[3003]; 

void solve1(ll n)
{
	ld dp[n+1][n+1];
	forA(i,0,n+1,1)forA(j,0,n+1,1)dp[i][j]=0;
	forA(i,0,n+1,1)
	{
		ll tails = n-i; if(i>tails)dp[0][i]=1.0; else dp[0][i]=0.0;
	}

	forA(i,1,n+1,1)
	{
		forA(j,0,n-i+1,1)
		{
			ld hp = c[i-1];  ld tp = 1.0-hp; 
			dp[i][j]= hp*dp[i-1][j+1] + tp*dp[i-1][j];
		}
	}
 cout<<fixed<<setprecision(10)<<dp[n][0]<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	ll n; cin>>n; forA(i,0,n,1)cin>>c[i];
	solve1(n);
	return 0;
}