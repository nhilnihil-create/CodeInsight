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
	int64 nn, hh, maxa = 0, ans = 0;
	cin >> nn >> hh;
	vector<int64> aa(nn), bb(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii] >> bb[ii];
		maxa = max(maxa, aa[ii]);
	}
	sort(bb.begin(), bb.end());
	for(int64 ii = nn - 1;ii >= 0;ii--)
	{
		if(bb[ii] < maxa)
		{
			break;
		}
		hh -= bb[ii];
		ans++;
		if(hh <= 0)
		{
			cout << ans << endl;
			return 0;
		}
	}
	ans += hh / maxa;
	if(hh % maxa != 0)
	{
		ans++;
	}
	cout << ans << endl;
	return 0;
}