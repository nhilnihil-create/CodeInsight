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
	int k;
	cin >> k;
	for (int i=0 ; i<n ; i++) cin >> cost[i];
	//memset(dp,INT_MAX,sizeof(dp+1));
	for (int i=1 ; i<=n ; i++)
	dp[i] = INT_MAX;
	dp[0] = 0;
	for (int i=0 ; i<n ; i++)
	{
		for (int j=i+1 ; j<= i+k ; j++)
		{
			if(j<n)
			{
				dp[j] = min(dp[j] , dp[i] + abs(cost[j] - cost[i]));
			}
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
