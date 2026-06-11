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
	vector<int64> aa(nn), ll(nn + 1), rr(nn + 1);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	ll[0] = 0;
	for(int64 ii = 1;ii <= nn;ii++)
	{
		ll[ii] = gcd(ll[ii - 1], aa[ii - 1]);
	}
	rr[nn] = 0;
	for(int64 ii = nn - 1;ii >= 0;ii--)
	{
		rr[ii] = gcd(rr[ii + 1], aa[ii]);
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		ans = max(ans, gcd(ll[ii], rr[ii + 1]));
	}
	cout << ans << endl;
	return 0;
}