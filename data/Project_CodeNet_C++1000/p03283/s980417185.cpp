#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,M,Q;cin >> N >> M >> Q;
	vector<vector<int>> dp(N+1,vector<int> (N+1,0));
	int L,R;
	for (int i=0;i<M;i++)
	{
		cin >> L >> R;
		dp[L][R]++;
	}
	for (int i=1;i<N+1;i++)
	{
		for (int j=1;j<N+1;j++)
		{
			dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	int p,q;
	for (int i=0;i<Q;i++)
	{
		cin >> p >> q;
		cout << dp[q][q]-dp[p-1][q]-dp[q][p-1]+dp[p-1][p-1] << endl;
	}
	return 0;
}