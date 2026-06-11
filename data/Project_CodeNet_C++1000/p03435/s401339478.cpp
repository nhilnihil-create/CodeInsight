#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	vector<vector<int>> cs(3, vector<int>(3));
	REP(i, 3) REP(j, 3) cin >> cs[i][j];
	bool isYes = true;
	REP(i, 3) REP(j, 3)
	{
		if (cs[i][j] - cs[i][(j + 1) % 3]
			!= cs[(i + 1) % 3][j] - cs[(i + 1) % 3][(j + 1) % 3])
			isYes = false;
		if (cs[i][j] - cs[(i + 1) % 3][j]
			!= cs[i][(j + 1) % 3] - cs[(i + 1) % 3][(j + 1) % 3])
			isYes = false;
	}
	cout << (isYes ? "Yes\n" : "No\n");
}