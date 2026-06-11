#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define frr(j,i,n) for(int i=j;i<=n;++i)
using namespace std;
int n;
double p[3001];
double dp[3001][3001];
double go(int index,int h)
{
	if(index==n)
	{
		if(h>(n-h))
			return (double)1;
		return (double)0;
	}
	if(dp[index][h]!=-1)
		return dp[index][h];

	double x=(p[index+1]*go(index+1,h+1));
	double y= (1-p[index+1])*go(index+1,h);
	
	return dp[index][h]= x +y;
	// return x+y;
}
void solve()
{
	frr(0,i,3000)
	{
		frr(0,j,3000)	dp[i][j]=-1;
	}
	cin>>n;
	frr(1,i,n)	cin>>p[i];
	cout<<fixed<<setprecision(10)<<go(0,0)<<"\n";
}
int main() 
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}

