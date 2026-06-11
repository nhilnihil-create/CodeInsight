#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;
map<ll, int> mp;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] == b[i] && b[i] == c[i]) + (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]);
	}
	cout << 2 * n - ans << endl;
	return 0;
}