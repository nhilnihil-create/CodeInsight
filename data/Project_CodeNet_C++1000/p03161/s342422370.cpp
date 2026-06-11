#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v(n);
	for(int&x:v) scanf("%d",&x);
	vector<int> dp(n+1,1e9);
	dp[0] = 0;
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= k; j++)
			if(i-j >= 0)
				dp[i] = min(dp[i], dp[i-j]+abs(v[i]-v[i-j]));
	printf("%d\n", dp[n-1]);
	return 0;
}
/*
5 3
10 30 40 50 20
0  20

*/ 