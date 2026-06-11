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
	vector<int> d(10);
	for (int i = 1; i <= 4; i++) d[i] = 0;
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		d[x]++;
	}
	if (d[1] <= 2 && d[2] <= 2 && d[3] <= 2 && d[4] <= 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}