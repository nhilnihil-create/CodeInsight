#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300010;

int n, k, a[MAXN];
int dp[MAXN];

int main()
{
	scanf("%d", &n);
	k = (1 << n);
	for(int i = 0; i < k; ++i) scanf("%d", &a[i]);
	dp[1] = a[0] + a[1];
	for(int i = 2; i < k; ++i)
	{
		int mx1 = 0, mx2 = 0;
		for(int j = i; ; j = (j - 1) & i)
		{
			if(a[j] > mx1) mx2 = mx1, mx1 = a[j];
			else if(a[j] > mx2) mx2 = a[j];
			if(!j) break;
		}
		dp[i] = max(dp[i - 1], mx1 + mx2);
	}
	for(int i = 1; i < k; ++i) printf("%d\n", dp[i]);
	return 0;
}