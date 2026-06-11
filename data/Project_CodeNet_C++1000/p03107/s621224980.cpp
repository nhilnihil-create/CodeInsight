#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	string S;
	cin >> S;

	int cur = 0;
	int ans = 0;
	for (auto c : S)
	{
		if (cur == 0)
		{
			if (c == '0')
			{
				--cur;
			}
			else
			{
				++cur;
			}
		}
		else if(cur > 0)
		{
			if (c == '0')
			{
				--cur;
				ans += 2;
			}
			else
			{
				++cur;
			}
		}
		else
		{
			if (c == '0')
			{
				--cur;
			}
			else
			{
				++cur;
				ans += 2;
			}
		}
	}

	cout << ans << endl;

	return 0;
}