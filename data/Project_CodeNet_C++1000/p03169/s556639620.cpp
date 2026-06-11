#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
map<int, int> cnts;
vector<vector<vector<double>>> DP;

int main()
{
	cin >> n;
	a.resize(n);
	int total = 0;
	// number of dishes with 0, 1, 2, 3 sushi in it
	cnts[0] = 0; cnts[1] = 0; cnts[2]; cnts[3] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
		cnts[a[i]]++;
	}

	//DP[i][j][k] is the expected number of operations needed  to clean up all dishes
	// i dishes has 1 pcs in it, j has 2 pcs in it, and k has 3 pcs in it

	DP.resize(cnts[1]+cnts[2]+cnts[3] + 1);
	for (int i = 0; i < cnts[1]+cnts[2]+cnts[3] + 1; i++)
	{
		DP[i].resize(cnts[2]+cnts[3]+1);
		for (int j = 0; j < cnts[2]+cnts[3] + 1; j++)
			DP[i][j].resize(cnts[3] + 1,0);
	}
	DP[0][0][0] = (double)0.0;

	for (int k = 0; k < cnts[3] + 1; k++)
	{
		for (int j = 0; j < cnts[2]+cnts[3]-k + 1; j++)
		{
			for (int i = 0; i < cnts[1]+cnts[2]+cnts[3]-j + 1; i++)
			{
				// dp[i][j][k] = i/n*dp[i-1][j][k]+j/n*dp[i+1][j-1][k]+k/n*dp[i][j+1][k-1]+(1-i/n-j/n-k/n)*dp[i][j][k]+1
				double tmp = 0;
				// cout << i << j << k << endl;
				tmp += 1;
				if (i > 0)
					tmp += ((double)i / n) * DP[i - 1][j][k];
				if (j > 0)
					tmp += ((double)j / n) * DP[i + 1][j - 1][k];
				if (k > 0)
					tmp += ((double)k / n) * DP[i][j + 1][k - 1];
				if(i+j+k!=0)
					DP[i][j][k] += ((double)n / ((double) i+j+k)) * tmp;
			}
		}
	}
	cout << setprecision(10) << DP[cnts[1]][cnts[2]][cnts[3]] << endl;
}