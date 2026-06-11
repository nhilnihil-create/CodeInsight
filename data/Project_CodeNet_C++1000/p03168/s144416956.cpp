#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define frr(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i<n;i++)
#define lli long long int
#define llu unsigned long long int
#define vi vector <int>
#define vii vector <long long int>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define mk make_pair
#define mpp map<int,int>
#define ff first
#define ss second
#define mod 1000000007

using namespace std;

vector <double> v1;
int n;
long double a[3001];
long double dp[3001][3001];
int vis[3001][3001];
long double solve(int i,int t)
{
	if(i == 0)
	{
		if(t <= n/2)
			return 1;
		else
			return 0;
	}

	if(vis[i][t])
		return dp[i][t];

	vis[i][t] = 1;
	long double x = (1-a[i])*solve(i-1,t) + a[i] * solve(i-1,t-1);
	return dp[i][t] = x;
}
void loop()
{
	//memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<fixed<<setprecision(10)<<solve(n,n);
}
int main()
{
	fast;
    int t=1;
    //cin>>t;
    while(t--)
    	loop();
}
