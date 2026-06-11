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

	long long x, y, ans;
	cin >> x >> y;
	if (x % y == 0) ans = -1;
	else {
		for (ans = x; (ans % y == 0); ans += x);
	}
	cout << ans << "\n";

	return 0;
}

