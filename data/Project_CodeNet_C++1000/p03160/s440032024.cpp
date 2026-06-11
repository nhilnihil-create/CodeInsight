#include<bits/stdc++.h>
using namespace std;

int findAns(vector<int> &A, vector<int> &dp, int i, int &ans)
{
	if(i > A.size())
		return A[i-2];

	if(i == A.size())
		return A[i-1];

	if(dp[i] != INT_MAX)
		return dp[i];


	ans += min(abs(A[i] - findAns(A, dp, i+1, ans)), abs(A[i] - findAns(A, dp, i+2, ans))) ;

	dp[i] = ans;

	return dp[i];

}

int findAnsItertavely(vector<int> &A, int n, vector<int> &dp)
{
	if(n <= 2)
		return abs(A[0] - A[n-1]);

	dp[0] = 0;
	dp[1] = abs(A[0] - A[1]);

	for(int i = 2; i < n; i++)
	{
		dp[i] = min(abs(A[i-2] - A[i]) + dp[i-2], abs(A[i-1] - A[i]) + dp[i-1]);
	}

	return dp[n-1];

}

int main()
{

	int n;
	cin>>n;

	vector<int> A(n, 0);
	for(int i = 0; i < n; i++)
		cin>>A[i];

	vector<int> dp(n, 0);
	int ans = 0;

	//int temp = findAns(A, dp, 0, ans);
	ans = findAnsItertavely(A, n, dp);

	cout<<ans<<endl;

	return 0;
}