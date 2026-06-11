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

	ll ans = 0;
	ll count = 0;
	for (int j = 0; j < S.size(); ++j)
	{
		if (S[j] == 'B')
		{
			++count;
		}
		else
		{
			ans += count;
		}
	}

	cout << ans << endl;
}