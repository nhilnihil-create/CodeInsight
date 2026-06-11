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
	string s;
	size_t K;
	cin >> s >> K;

	set<string> substrs;
	for(int i = 1; i <= min(s.size(), K); ++i)
	{
		for (int j = 0; j + i - 1 < s.size(); ++j)
		{
			substrs.insert(s.substr(j, i));
		}
	}

	auto it = substrs.begin();
	rep(i, K-1)
	{
		++it;
	}

	cout << *it << endl;
}