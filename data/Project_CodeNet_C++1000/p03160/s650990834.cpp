#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int&x:v) scanf("%d",&x);
	vector<int> dp(n+1);
	dp[1] = abs(v[0]-v[1]);
	for(int i = 2; i < n; i++)
		dp[i] = min(dp[i-1]+abs(v[i]-v[i-1]), dp[i-2]+abs(v[i]-v[i-2]));
	printf("%d\n", dp[n-1]);
	return 0;
}