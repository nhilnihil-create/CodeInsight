#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main(){
	int n; cin >> n;
	vector<string> grid(n);
	rep(i, 0, n) cin >> grid[i];
	int ans = 0;
	rep(k, 0, n) {
		bool flag = true;
		rep(i, 0, n)rep(j, 0, n) {
			if (grid[i][j] != grid[(j + k) % n][(i + n - k) % n]) flag = false;
		}
		if (flag) ans += n;
	}
	printf("%d", ans);
	return 0;
}
