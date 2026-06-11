#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

int main()
{
	uint64 nn, mm, ans = 0;
	cin >> nn >> mm;
	vector<pair<int64, int64>> memo(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> memo[ii].first >> memo[ii].second;
	}
	sort(memo.begin(), memo.end());
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(memo[ii].second <= mm)
		{
			mm -= memo[ii].second;
			ans += memo[ii].second * memo[ii].first;
		}
		else
		{
			ans += mm * memo[ii].first;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}