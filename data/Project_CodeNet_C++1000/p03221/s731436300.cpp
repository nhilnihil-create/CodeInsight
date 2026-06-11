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
	int64 nn, mm;
	cin >> nn >> mm;
	vector<pair<int64, int64>> memo(mm), aa(mm);
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> aa[ii].first >> aa[ii].second;
		memo[ii] = aa[ii];
	}
	sort(memo.begin(), memo.end());
	for(int64 ii = 0;ii < mm;ii++)
	{
		pair<int64, int64> tmp1 = make_pair(aa[ii].first, 0);
		auto tmp2 = lower_bound(memo.begin(), memo.end(), tmp1);
		tmp1.second = aa[ii].second;
		auto tmp3 = lower_bound(memo.begin(), memo.end(), tmp1);
		for(int64 jj = 0;jj < 5 - (int64)log10(aa[ii].first);jj++)
		{
			cout << '0';
		}
		cout << aa[ii].first;
		for(int64 jj = 0;jj < 5 - (int64)log10(distance(tmp2, tmp3) + 1);jj++)
		{
			cout << '0';
		}
		cout << (distance(tmp2, tmp3) + 1) << endl;
	}
	return 0;
}