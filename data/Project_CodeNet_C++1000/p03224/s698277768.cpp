#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
6
)");
#define cin input
#endif

int main()
{
	int n;
	cin >> n;

	int k = sqrt((long double)n * 2) + 1;
	if (k * (k - 1) / 2 == n)
	{
		cout << "Yes" << endl;
		cout << k << endl;
		REP (i, k)
		{
			cout << k - 1;
			int x = i * (i - 1) / 2;
			REP (j, i)
				cout << ' ' << ++x;
			++x;
			FOR (j, i, k - 1)
				cout << ' ' << (x += j);
			cout << endl;
		}
	} else
		cout << "No" << endl;

	return 0;
}
/*
0
11
223
3456
47890
 01234
 */