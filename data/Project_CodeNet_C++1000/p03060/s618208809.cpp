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
	int64 nn, ans = 0;
	cin >> nn;
	vector<int64> be(nn), vv(nn), cc(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> vv[ii];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> cc[ii];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		be[ii] = vv[ii] - cc[ii];
	}
	sort(be.begin(), be.end());
	reverse(be.begin(), be.end());
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(be[ii] <= 0)
		{
			break;
		}
		ans += be[ii];
	}
	cout << ans << endl;
	return 0;
}