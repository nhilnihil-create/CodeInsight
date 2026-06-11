#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MaxN = 1123456;
const ll mod = 1000000007;
const ll inf = 1000000005LL;

double dp[305][305][305];

class Solver {
    int n;
	int* a;
	public:
	Solver(int nn) {
		n = nn;
		a = new int[n + 1];
		solve();
	}
	
	void solve() {
		ll x = 0, y = 0, z = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) x++;
			if (a[i] == 2) y++;
			if (a[i] == 3) z++;
		}
		
		cout << go(x, y, z);
	}
	
	double go(int x, int y, int z) {
		if (!x && !y && !z) return 0;
		if (dp[x][y][z] > 0) return dp[x][y][z];
		
		double sum = x + y + z;
		double ans = n / sum;
		if (x) ans += x / sum * go(x - 1, y, z);
		if (y) ans += y / sum * go(x + 1, y - 1, z);
		if (z) ans += z / sum * go(x, y + 1, z - 1);
		return dp[x][y][z] = ans;
	}
};

void solve_case() {
	//cout << "hell";
    int n;
	cin >> n;
	cout << setprecision(30) << fixed;
	Solver s(n);
}

signed main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    
    int t=1;
    //cin >> t;
    while(t--) solve_case();
}
