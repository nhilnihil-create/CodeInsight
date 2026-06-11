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

	long double n, m, d, ans;
	long long i, j, k;

	cin >> n >> m >> d;
	if (d == 0) ans = 1.0 / n;
	else {
		ans = (n - d) * 2.0 / (n * n);
	}

	ans *= (m - 1);

	cout << setprecision(10) << fixed << ans << "\n";


	return 0;
}

