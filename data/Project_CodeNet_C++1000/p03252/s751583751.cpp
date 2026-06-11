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
	string S, T;
	cin >> S >> T;

	unordered_map<char, char> table1, table2;

	string ans = "Yes";
	rep(i, S.size())
	{
		if (table1.find(S[i]) == table1.end())
		{
			table1[S[i]] = T[i];
		}
		else
		{
			if (table1[S[i]] != T[i])
			{
				ans = "No";
				break;
			}
		}

		if (table2.find(T[i]) == table2.end())
		{
			table2[T[i]] = S[i];
		}
		else
		{
			if (table2[T[i]] != S[i])
			{
				ans = "No";
				break;
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}