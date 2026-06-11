#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> arr;
typedef vector<arr> matrix;
typedef vector<ll> longarr;
typedef vector<longarr> longmat;
typedef map<int, arr> graph;
typedef vector<char> chararr;
typedef vector<chararr> charmat;
typedef pair<int, int> fraction;
double dp[301][301][301];
double solve(int x, int y, int z, int n) {
	if (x < 0 || y < 0 || z < 0)
		return 0;
	if (x == 0 && y == 0 && z == 0)
		return 0;
	if (dp[x][y][z] > -0.9)
		return dp[x][y][z];
	double exp = n + x * solve(x - 1, y, z, n) + y * solve(x + 1, y - 1, z, n) + z * solve(x, y + 1, z - 1, n);
	return dp[x][y][z] = exp / (x + y + z);
}

int main() {

	int n;
	cin >> n;
	int one = 0;
	int two = 0;
	int three = 0;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x == 1) ++one;
		else if (x == 2) ++two;
		else ++three;
	}
	memset(dp, -1, sizeof(dp));
	cout << fixed << setprecision(10) << solve(one, two, three, n);
}