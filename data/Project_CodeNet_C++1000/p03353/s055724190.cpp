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

string next_substr(string& str, string& substr)
{
	string next_str = "";
	string work_str = substr;
	while (true)
	{
		std::string::size_type pos = 0;
		while(true)
		{
			pos = str.find(work_str, pos);
			if (pos == std::string::npos) break;
			if (pos + work_str.size() >= str.size()) break;
			string cand = work_str + str[pos + work_str.size()];
			if (substr < cand && (next_str == "" || next_str > cand))
			{
				next_str = cand;
			}

			++pos;
		}

		if (next_str != "") break;
		work_str.pop_back();
	}

	return next_str;
}

int main()
{
	string s;
	int K;
	cin >> s >> K;

	string substr = "";
	rep(i, K)
	{
		substr = next_substr(s, substr);
	}

	cout << substr << endl;
}