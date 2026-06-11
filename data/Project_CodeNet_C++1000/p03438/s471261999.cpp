#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;

int main()
{
	int N; cin >> N;
	vector<LLONG> as(N), bs(N);
	REP(i, N) cin >> as[i];
	REP(i, N) cin >> bs[i];
	// 左端から順に合わせていく
	LLONG upNum = 0;
	REP(i, N)
	{
		if (as[i] > bs[i])
		{
			upNum += as[i] - bs[i];
			bs[i] = as[i];
		}
	}
	REP(i, N)
	{
		if (as[i] < bs[i])
		{
			upNum -= (bs[i] - as[i]) / 2;
		}
	}
	cout << (upNum <= 0 ? "Yes\n" : "No\n");
}