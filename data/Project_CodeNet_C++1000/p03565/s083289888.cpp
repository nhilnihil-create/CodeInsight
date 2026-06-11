#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	string s, t; cin >> s >> t;
	// 部分文字列の該当箇所のうち，なるべく後ろの方にある場所を探す
	int pos = -1;
	for (int i = 0; i + t.length() <= s.length(); ++i)
	{
		bool ok = true;
		for (int j = 0; j < t.length(); ++j)
		{
			if (s[i + j] != '?' && s[i + j] != t[j])
			{
				ok = false;
				break;
			}
		}
		if (ok) pos = i;
	}
	if (pos == -1)
	{
		cout << "UNRESTORABLE" << endl;
	}
	else
	{
		for (int j = 0; j < t.length(); ++j)
		{
			s[pos + j] = t[j];
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '?') s[i] = 'a';
		}
		cout << s << endl;
	}
}
