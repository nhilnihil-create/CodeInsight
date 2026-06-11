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



int main() {
	int n; cin >> n;
	if (n == 3) printf("2 5 63");
	else if (n == 4) printf("2 5 20 63");
	else if (n == 5) printf("2 5 20 60 63");
	else {
		int sum = 0;
		set<int> ans;
		rep(i, 1, 30001) {
			if (i % 2 == 0 || i % 3 == 0) {
				ans.insert(i);
				sum += i;
			}
			if (ans.size() > n - 1) break;
		}
		sum %= 6;
		if (sum == 2) {
			ans.erase(ans.lower_bound(8));
			ans.insert((n / 4 + 1) * 6);
		}
		if (sum == 3) {
			ans.erase(ans.lower_bound(9));
			ans.insert((n / 4 + 1) * 6);
		}
		if (sum == 5) {
			ans.erase(ans.lower_bound(9));
			ans.insert((n / 4 + 1) * 6 - 2);
		}
		for (int a : ans) printf("%d ", a);
	}
	return 0;
}
