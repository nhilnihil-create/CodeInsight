#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using li = __int128;
using uli = unsigned __int128;

#define fi first
#define se second

template <typename T> void s_min(T& a, T b) {
	if (a > b) a = b;
}

template <typename T> void s_max(T& a, T b) {
	if (a < b) a = b;
}

const int MAXN = 305;
int N, a[4];
double dp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];

double rec(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) return 0;
	if (x == 0 && y == 0 && z == 0) return 0;
	if (vis[x][y][z]) return dp[x][y][z];
	vis[x][y][z] = true;
	int rem = x + y + z;
	double val = N + x * rec(x - 1, y, z) + y * rec(x + 1, y - 1, z) + z * rec(x, y + 1, z - 1);
	return dp[x][y][z] = val / rem;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		a[x]++;
	}
	double ans = rec(a[1], a[2], a[3]);
	cout << fixed << setprecision(12) << ans;

	return 0;
}