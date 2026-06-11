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

int main() {
	int d, n;
	int m;
	int ans;
	cin >> d >> n;
	if (d == 0)m = 1;
	else if (d == 1)m = 100;
	else if (d == 2)m = 10000;
	if (n != 100) {
		ans = n * m;
	}
	else {
		ans = (n + 1) * m;
	}
	cout << ans << endl;
		return 0;
	}
