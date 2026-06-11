#include<bits/stdc++.h>
using namespace std;
long long dp[100];
long long lucas_num(long long n)
{
	if(n==0)
		return 2;
	if(n==1)
		return 1;
	if(dp[n]==-1)
	{
		dp[n] = lucas_num(n-1)+ lucas_num(n-2);
	}
	return dp[n];
}
int main()
{
	long long n;
	cin>>n;
	for (long long i = 0; i < 100; ++i)
	{
		dp[i] = -1;
	}
	cout<<lucas_num(n)<<endl;
	return 0;
}