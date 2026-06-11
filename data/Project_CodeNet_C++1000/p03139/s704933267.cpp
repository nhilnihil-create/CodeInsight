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

	int n, a, b, ans1, ans2;
	cin >> n >> a >> b;
	if (a + b <= n) ans1 = 0;
	else ans1 = a + b - n;

	ans2 = min(a, b);
	cout << ans2 << " " << ans1 << "\n";

	return 0;
}
