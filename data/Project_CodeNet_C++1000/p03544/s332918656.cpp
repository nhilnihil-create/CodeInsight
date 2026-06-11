#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[100];

ll l(ll n)
{
	
	if(n==0)
	{
		return dp[n]=2;
	}
	if(n==1)return dp[n] = 1;
	if(dp[n]!=0)return dp[n];
	return dp[n] = l(n-1)+l(n-2);
}

int main()
{
	ll n;
	cin >> n;
	cout << l (n)<<endl;
	return 0;
}
