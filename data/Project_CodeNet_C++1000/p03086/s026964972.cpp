#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	string S;
	cin >> S;

	int len = S.length();

	int s_max = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 1; j <= (len - i); ++j)
		{
			string ls = S.substr(i, j);
			bool judge = true;
			int l_max = 0;
			for (auto e : ls)
			{
				if (e != 'A' && e != 'C' && e != 'G' && e != 'T')
				{
					judge = false;
					break;
				}
			}

			if (judge)
			{
				s_max = max(s_max, (int)ls.length());
			}
		}
	}

	cout << s_max << endl;

	return 0;
}