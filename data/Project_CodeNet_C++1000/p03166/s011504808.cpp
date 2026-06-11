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

vector <int> v[100001];
vector <int> vis(100001);
int dp[100001];
int dfs(int node)
{
	if(vis[node])
		return dp[node];
	vis[node] = 1;
	int mx = 0;
	for(auto child : v[node])
		mx = max(mx,dfs(child) + 1);
	return dp[node] = mx;
}

void loop()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
	}
	int mx = 0;
	for(int i=1;i<=n;i++)
		mx = max(mx,dfs(i));
	cout<<mx<<"\n";
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fast;
    int t=1;
    //cin>>t;
    while(t--)
    	loop();
}
