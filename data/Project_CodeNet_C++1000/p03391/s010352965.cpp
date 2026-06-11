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
3
8 3
0 1
4 8
)");
#define cin input
#endif

int main()
{
	int n;
	cin >> n;

	ll s = 0;
	int m = 1 << 30;
	REP (i, n)
	{
		int a, b;
		cin >> a >> b;
		s += a;
		if (a > b)
			m = min(m, b);
	}

	cout << (m == 1 << 30 ? 0 : s - m) << endl;

	return 0;
}
