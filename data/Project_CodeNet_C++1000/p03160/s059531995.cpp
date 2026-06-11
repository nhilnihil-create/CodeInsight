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

int cost[maxn];
int dp[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i=0 ; i<n ; i++) cin >> cost[i];
	dp[0] = 0;
	for (int i=1 ; i<n ; i++)
	{
		if(i==1) dp[i] = dp[i-1] + abs(cost[i] - cost[i-1]);
		else
		dp[i] = min(dp[i-1] + abs(cost[i] - cost[i-1]) , dp[i-2] + abs(cost[i] -  cost[i-2]));
	}
	cout << dp[n-1] << endl;
	return 0;
}
