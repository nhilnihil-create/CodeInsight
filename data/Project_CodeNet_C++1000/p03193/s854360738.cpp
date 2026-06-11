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

	int ans = 0, n, i, j, k, h, w, x, y;
	cin >> n >> h >> w;
	while (n--) {
		cin >> x >> y;
		if ((x >= h) && (y >= w)) ans++;
	}
	cout << ans << "\n";

	return 0;
}
