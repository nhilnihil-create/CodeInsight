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
	int N;
	cin >> N;

	auto ans = 0ll;
	auto a = 0;
	auto b = 0;
	auto ab = 0;
	for (auto i = 0; i < N; ++i)
	{
		string s;
		cin >> s;

		for (auto i = 0; i < (int)s.length() - 1; ++i)
		{
			if (s[i] == 'A' && s[i + 1] == 'B')
			{
				++ans;
			}
		}

		if (s[0] == 'B')
		{
			if (s[s.length() - 1] == 'A')
			{
				++ab;
			}
			else
			{
				++b;
			}
		}
		else if (s[s.length() - 1] == 'A')
		{
			++a;
		}
	}

	if (ab > 0)
	{
		ans += ab - 1;
		if (a > 0)
		{
			++ans;
			--a;
		}
		if (b > 0)
		{
			++ans;
			--b;
		}
	}
	ans += min(a, b);

	cout << ans << endl;

	return 0;
}