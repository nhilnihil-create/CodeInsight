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

	int n, i, j, k, x, a, b, c0 = 0, c1 = 0, c2 = 0, ans;
	cin >> n >> a >> b;
	while (n--) {
		cin >> x;
		if (x <= a) c0++;
		else if (x <= b) c1++;
		else c2++;
	}
	ans = min(c0, min(c1, c2));
	cout << ans << "\n";

	return 0;
}
