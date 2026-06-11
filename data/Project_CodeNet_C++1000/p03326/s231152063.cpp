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
	int64 nn, mm, xx, yy, zz;
	cin >> nn >> mm;
	vector<int64> aa000(nn), aa001(nn), aa010(nn), aa011(nn), aa100(nn), aa101(nn), aa110(nn), aa111(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> xx >> yy >> zz;
		aa000[ii] =  xx + yy + zz;
		aa001[ii] =  xx + yy - zz;
		aa010[ii] =  xx - yy + zz;
		aa011[ii] =  xx - yy - zz;
		aa100[ii] = -xx + yy + zz;
		aa101[ii] = -xx + yy - zz;
		aa110[ii] = -xx - yy + zz;
		aa111[ii] = -xx - yy - zz;
	}
	sort(aa000.begin(), aa000.end());
	sort(aa001.begin(), aa001.end());
	sort(aa010.begin(), aa010.end());
	sort(aa011.begin(), aa011.end());
	sort(aa100.begin(), aa100.end());
	sort(aa101.begin(), aa101.end());
	sort(aa110.begin(), aa110.end());
	sort(aa111.begin(), aa111.end());
	int64 ans = 0, tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa000[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa001[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa010[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa011[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa100[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa101[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa110[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	tmp = 0;
	for(int64 ii = 0;ii < mm;ii++)
	{
		tmp += aa111[nn - 1 - ii];
	}
	ans = max(ans, tmp);
	cout << ans << endl;
	return 0;
}