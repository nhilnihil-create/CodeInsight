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

void Solve(string s, vector<int> &xNums, string &seps)
{
	int xNum = 0;
	for (const char ch : s)
	{
		if (ch == 'x')
		{
			++xNum;
		}
		else
		{
			xNums.push_back(xNum);
			seps.push_back(ch);
			xNum = 0;
		}
	}
	xNums.push_back(xNum);
}

int main()
{
	string s; cin >> s;
	int l = 0, r = s.length() - 1;
	int ans = 0;
	while (l < r)
	{
		if (s[l] == s[r])
		{
			// 文字が等しいとき，操作せず内側へ進む
			++l; --r;
		}
		else if (s[l] == 'x')
		{
			// 先頭だけがｘのとき，末尾にｘを加えて進む
			++l;
			++ans;
		}
		else if (s[r] == 'x')
		{
			// 末尾だけがｘのとき，先頭にｘを加えて進む
			--r;
			++ans;
		}
		else
		{
			// 互いにｘ以外の文字で異なるとき，回分にはならない
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
}
