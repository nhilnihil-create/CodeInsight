#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
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

	auto result = 0;
	auto right = (int)s.length() - 1;
	for (auto left = 0; left < right; ++left)
	{
		if (s[left] == s[right])
		{
			--right;
		}
		else if(s[left] == 'x')
		{
			++result;
		}
		else
		{
			while (s[right] == 'x')
			{
				++result;
				--right;
			}
			if (s[left] != s[right])
			{
				result = -1;
				break;
			}
			--right;
		}
	}

	cout << result << endl;

	return 0;
}