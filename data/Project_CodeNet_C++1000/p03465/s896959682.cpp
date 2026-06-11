#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
// #define int long long

const int N = 4e6 + 5;

bitset<N> dp;
				
int32_t main() {
	fast_cin();  
	int n; cin >> n;
	dp.set(0);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		sum += a;
		dp |= (dp << a);
	}
	sum = (sum + 1) / 2;
	for (int i = sum; ; ++i) {
		if (dp[i]) {
			cout << i << endl;
			break;
		}
	}
	return 0;	
}