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

lli dp[1001][1001];
int a[1001][1001];

lli solve(int i,int j,int n,int m)
{
	if(i>n || j>m)
		return 0;

	if(i == n && j == m)
		return 1;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(a[i][j] == 0)
		return 0;

	return dp[i][j] = ((solve(i+1,j,n,m)%mod) + (solve(i,j+1,n,m)%mod))%mod;
}
void loop()
{
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	//int a[n+1][m+1];
	char ch;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch == '.')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	cout<<solve(1,1,n,m)<<"\n";
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	//fast;
    int t=1;
    //cin>>t;
    while(t--)
    	loop();
}
