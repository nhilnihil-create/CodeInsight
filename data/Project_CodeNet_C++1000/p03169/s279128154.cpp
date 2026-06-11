#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
const int maxn = 100005;
int n;
double dp[301][301][301];
double solve(int x, int y, int z) {
	if (x == 0 && y ==0 && z == 0) {
		return 0;
	}
	if (dp[x][y][z] != 0) {
		return dp[x][y][z];
	}
	double ans = 0;
	double add = (double)n / (double)(x + y + z);;
	if (x) {
		ans += (add + solve(x - 1, y, z)) / (double)(x + y + z) * (double)x;
	}
	if (y) {
		ans += (add + solve(x + 1, y - 1, z)) / (double)(x + y + z) * (double)y;
	}
	if (z) {
		ans += (add + solve(x, y + 1, z - 1)) / (double)(x + y + z) * (double)z;
	}
	return dp[x][y][z] = ans;
}
void go() {
	cin >> n;
	int c[3] = {};
	f(n) {
		int x;
		cin >> x;
		c[x - 1]++;
	}
	cout << fixed << setprecision(10) << solve(c[0], c[1], c[2]) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}