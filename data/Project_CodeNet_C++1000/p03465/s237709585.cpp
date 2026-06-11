#include"bits/stdc++.h"
#include<cassert>
using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 998244353;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
int a[2005];
bitset<4000005>dp;
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	int sum = 0;
	rep(i, n)sum += a[i];
	dp[0] = 1;
	rep(i, n) {
		dp |= (dp << a[i]);
	}
	for (int i = (sum + 1) / 2; i <= sum;i++) {
		if (dp[i]) {
			cout << i << endl;
			return 0;
		}
	}
}