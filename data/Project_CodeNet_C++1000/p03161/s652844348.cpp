#include<bits/stdc++.h>
using namespace std;

int findAnsItertavely(vector<int> &A, int n, int k, vector<int> &dp)
{
	dp[0] = 0;

	for(int i = 1; i < n; i++)
	{
		for(int j = i-k; j < i; j++)
		{
			if(j >= 0)
				dp[i] = min(abs(A[i] - A[j]) + dp[j], dp[i]);
		}
	}

	return dp[n-1];

}

int main()
{

	int n, k;
	cin>>n>>k;

	vector<int> A(n, 0);
	for(int i = 0; i < n; i++)
		cin>>A[i];

	vector<int> dp(n, INT_MAX);
	int ans = 0;

	ans = findAnsItertavely(A, n, k, dp);
	
	cout<<ans<<endl;

	return 0;
}