#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	string s;
	cin >> s;

	vector<pair<char, int>> list;
	for (auto i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] != 'x')
		{
			list.push_back({ s[i], i });
		}
	}

	auto valid = true;
	auto len = (int)list.size();
	for (auto i = 0; i < len / 2; ++i)
	{
		if (list[i].first != list[len - i - 1].first)
		{
			valid = false;
		}
	}

	auto ans = -1;
	if (valid)
	{
		ans = 0;
		if (len > 0)
		{
			auto left = len / 2;
			auto right = len / 2;
			if (len % 2 == 0)
			{
				--left;
			}
			left = list[left].second;
			right = list[right].second;
			while (left >= 0 || right < (int)s.length())
			{
				if (left < 0)
				{
					++ans;
					++right;
				}
				else if (right >= (int)s.length())
				{
					++ans;
					--left;
				}
				else if (s[left] == s[right])
				{
					++right;
					--left;
				}
				else if (s[left] == 'x')
				{
					--left;
					++ans;
				}
				else
				{
					++right;
					++ans;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}