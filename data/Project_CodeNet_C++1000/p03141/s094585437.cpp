#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans;
	cin >> n;
	vector<long long> a(n), b(n), c(n);
	ans = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c[i] = a[i] + b[i];
		ans -= b[i];
	}
	sort(c.rbegin(), c.rend());
	for (i = 0; i < n; i+= 2) ans += c[i];
	cout << ans << "\n";

	return 0;
}

