#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
//#define int long long

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	if (a + b == 15) {
		cout << '+' << endl;
		return 0;
	}
	if (a * b == 15) {
		cout << '*' << endl;
		return 0;
	}
	cout << 'x' << endl;
	return 0;
}
