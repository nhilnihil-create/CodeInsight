# include <bits/stdc++.h>
using namespace std;
#define int long long
#define pbdouble(x)	cout<<fixed<<setprecision(14)<<x;
int mod = 1e9 + 7;
double memo[305][305][305];
double top(int x, int y, int z, int n)
{
	if (x < 0 || y < 0 || z < 0)
		return 0;
	if (x == 0 && y == 0 && z == 0)
		return 0;
	double &ans = memo[x][y][z];
	if (ans > -0.9) return ans;
	ans = n + (x * top(x - 1, y, z, n)) + (y * top(x + 1, y - 1, z, n)) + (z * top(x, y + 1, z - 1, n));
	return ans /= (x + y + z);
}
int32_t main ()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int one = 0, two = 0, three = 0;
	int d;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		if (d == 1) one++;
		else if (d == 2) two++;
		else three++;
	}
	pbdouble(top(one, two, three, n));
}
// 10
// 1 3 2 3 3 2 3 2 1 3

// 54.48064457488221