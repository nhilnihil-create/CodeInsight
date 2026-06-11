#include<bits/stdc++.h>
using namespace std;
#define ll long long

//
int n;
vector<int>a;
vector<int>dp;
//

bool F(int k)
{
	if (k == 0)
		return 0;
	if (dp[k] != -1)
		return dp[k];
	for (auto it : a)
	{
		if (it <= k)
		{
			if (!F(k - it))
				return (dp[k] = 1);
		}
	}
	return (dp[k] = 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; int k; cin >> k;
	a = vector<int>(n);
	dp = vector<int>(k + 1, -1);
	for (auto &it : a)
		cin >> it;
	cout << (F(k) ? "First" : "Second");

	return 0;
}