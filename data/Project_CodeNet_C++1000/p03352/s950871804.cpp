#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

bool exp(int n) {
	int m = 1;
	if (n == 1)return 1;
	for (int i = 2; i < n; i++) {
		while (m <= n) {
			m *= i;
			if (m == n)return 1;
		}
		m = 1;
	}
	return 0;
}

int main() {
	int x;
	cin >> x;
	vector<bool> f(1001);
	for (int i = x; i > 0; i--) {
		if (exp(i) == 1) {
			cout << i << endl;
			return 0;
		}
	}
}