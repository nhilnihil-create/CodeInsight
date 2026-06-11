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

	int a, b, c, ans = 0, x;
	cin >> a >> b >> c;
	x = min(b, c);
	ans += 2 * x;
	b -= x; c -= x;
	x = min(a, c);
	ans += x;
	a -= x; c -= x;
	if (c > 0) ans++;
	if (b > 0) ans += b;

	cout << ans << "\n";


	return 0;
}

