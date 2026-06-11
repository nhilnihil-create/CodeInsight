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
	string s; cin >> s;
	map<char, int> ch2NumMap;
	for (const char ch : s)
	{
		++ch2NumMap[ch];
	}
	// 26文字以下ならば，使われていない文字の内，もっとも若い文字を後ろにつければよい
	if (s.length() < 26)
	{
		for (char ch = 'a'; ch <= 'z'; ++ch)
		{
			if (ch2NumMap.count(ch) == 0)
			{
				cout << s + ch << endl;
				return 0;
			}
		}
	}
	// 26文字のときの例外ケース
	else if (s == "zyxwvutsrqponmlkjihgfedcba")
	{
		cout << -1 << endl;
	}
	// それ以外の26文字のとき，後ろを削りながら文字を進めて
	// 多彩になる文字列を探す
	else
	{
		int len = s.length();
		for (int i = len - 1; i >= 0; --i)
		{
			// 後ろの文字を削り，先の文字に進めていく
			char back = s.back();
			s.pop_back();
			ch2NumMap[back] = 0;
			for (char ch = back + 1; ch <= 'z'; ++ch)
			{
				// 既に削られた文字に当たった場合，
				// 最後尾をその文字に置換することで多彩になる
				if (ch2NumMap[ch] == 0)
				{
					cout << s + ch << endl;
					return 0;
				}
			}
		}
	}
}
