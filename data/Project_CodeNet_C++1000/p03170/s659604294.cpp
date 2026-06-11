#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const int  M = 1e9 + 7;
int n, k;

int dp[100002][2];

int f(int sum, int winner, vector<int> &v)
{
	//cout << sum <<  " " << winner << endl;
	if(sum < 0)         // means were on the last stone
	{
		return !(winner);
	}
	if(dp[sum][winner] != -1)
		return dp[sum][winner];
	int temp = winner;
	for(int i = 0; i < n; i++)
	{
		int ans = (sum - v[i] < 0 || dp[sum-v[i]][!winner] == -1) ? f(sum - v[i], !(winner), v) : dp[sum-v[i]][!winner];
		if(ans != temp)
		{
			temp = !(winner);
			break;
		}
	}
	return dp[sum][winner] = temp;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j, wt, m;
	
	cin >> n >> k;
	vector<int> v(n);
	for(i = 0; i < n; i++)
		cin >> v[i];

	memset(dp, -1, sizeof(dp));

	(f(k, 0, v) == 0) ? (cout <<"Second") : (cout << "First");
}
