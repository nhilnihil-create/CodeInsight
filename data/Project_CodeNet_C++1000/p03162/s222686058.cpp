/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main()
{
	int n;
	cin >> n;
	vector<int> hap[n+5];
	vector<int> dp[n+5];
	for (int i=0 ; i<n ; i++) 
	{
		int a,b,c;
		cin >> a >> b >> c;
		hap[i].pb(a);
		hap[i].pb(b);
		hap[i].pb(c);
		dp[i].pb(0);
		dp[i].pb(0);
		dp[i].pb(0);
	}
	//memset(dp,0,sizeof(dp));
	dp[0][0] = hap[0][0];
	dp[0][1] = hap[0][1];
	dp[0][2] = hap[0][2];
	for(int i = 1; i < n; i++){
			dp[i][0] = hap[i][0]+max(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = hap[i][1]+max(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = hap[i][2]+max(dp[i-1][0], dp[i-1][1]);
	}
	int ans = *max_element(dp[n-1].begin(),dp[n-1].end());
//	for (int i=0 ; i<n ; i++)
//	{
//		ans = max(ans,dp[n-1][i]);
//	}
	cout << ans << endl;
	return 0;
}
