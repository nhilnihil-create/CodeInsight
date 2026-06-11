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
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	ll N;
	cin >> N;
	string S;

	ll i = 1;

	while (true)
	{
		if (abs(N) % (2 * abs(i)) == 0)
		{
			S.push_back('0');
		}
		else
		{
			S.push_back('1');
			N -= i;
		}

		if (N == 0) break;

		i *= -2;
	}

	reverse(S.begin(), S.end());

	cout << S << endl;
	
	return 0;
}