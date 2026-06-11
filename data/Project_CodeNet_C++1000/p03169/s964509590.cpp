#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<vector<double>>>dp(303, vector<vector<double>>(303, vector<double>(303, -1)));
int n;
double F(int x, int y, int z)
{
	if (x == 0 && y == 0 && z == 0)
		return 0;
	if (dp[x][y][z] != -1)
		return dp[x][y][z];
	double ans = n;
	if (x)
		ans += x * F(x - 1, y, z);
	if (y)
		ans += y * F(x + 1, y - 1, z);
	if (z)
		ans += z * F(x, y + 1, z - 1);
	return (dp[x][y][z] = ans / (x + y + z));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; vector<int>a(n);
	int x = 0; int y = 0; int z = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		x += (a[i] == 1);
		y += (a[i] == 2);
		z += (a[i] == 3);
	}
	cout << fixed << setprecision(11) << F(x, y, z);

	return 0;
}