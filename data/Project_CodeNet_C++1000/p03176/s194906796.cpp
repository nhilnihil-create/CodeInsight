//https://atcoder.jp/contests/dp/tasks/dp_q
// use of upper bound and lower bound on map
# include <bits/stdc++.h>
using namespace std;
#define int long long int
struct flower
{
	int h;
	int b;
};
int bottom(flower f[], int n)
{
	map<int, int> m;//only stores the eligble elements'
	//that too in increasing order enabling us to
	//use upperbound fxn in just logn complexity
	int dp[n + 1];
	dp[0] = f[0].b;
	m[f[0].h] = f[0].b;
	int ans = f[0].b;
	for (int i = 1; i < n; i++)
	{
		dp[i] = f[i].b;
		auto it = m.upper_bound(f[i].h);
		auto it2 = it;
		if (it != m.begin())
		{
			it--;
			dp[i] += it->second;
		}
		it = it2;
		while (it != m.end() && it->second <= dp[i])
		{
			auto temp = it;
			temp++;
			m.erase(it);
			it = temp;
		}
		m[f[i].h] = dp[i];
		ans = max(ans, dp[i]);
	}
	return ans;
}
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	flower f[n];
	for (int i = 0; i < n; i++)
	{
		cin >> f[i].h;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> f[i].b;
	}
	cout << bottom(f, n);
}
// 9
// 4 2 5 8 3 6 1 7 9
// 6 8 8 4 6 3 5 7 5

// 31
