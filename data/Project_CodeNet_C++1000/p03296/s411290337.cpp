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

	int n, i, j, k, ans;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) cin >> a[i];
	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = i; (j < n) && (a[i] == a[j]); j++);
		ans += (j - i) / 2;
		i = j - 1;
	}
	cout << ans << "\n";

	return 0;
}
