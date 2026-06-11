#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
	LLONG X, Y; cin >> X >> Y;
	if (X % Y == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		LLONG ans = X;
		while (ans <= 1e18)
		{
			if (ans % Y != 0) break;
			ans += X;
		}
		cout << ans << endl;
	}
}