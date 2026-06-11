#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define uii             unordered_map<int,int>
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
void S_K_S()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int32_t main()
{
	S_K_S();
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int dp[n];
	int ans=INT_MAX;
	dp[0]=0;
	for(int i=1;i<n;i++){
		int j=min(i,k);
		dp[i]=INT_MAX;
		for(int l=1;l<=j;l++){
			dp[i]=min(dp[i],dp[i-l]+abs(a[i]-a[i-l]));
		}
	}
	cout<<dp[n-1];
}
