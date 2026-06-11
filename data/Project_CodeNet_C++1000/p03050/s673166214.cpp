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
	int64 nn, tmp, ans = 0;
	cin >> nn;
	if(nn == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	set<int64> memo;
	for(int64 ii = 2;ii <= sqrt(nn);ii++)
	{
		if(nn % ii == 0)
		{
			memo.insert(ii);
			memo.insert(nn / ii);
		}
	}
	memo.insert(nn);
	for(auto ite = memo.begin();ite != memo.end();ite++)
	{
		tmp = *ite;
		tmp--;
		if(nn % tmp == nn / tmp)
		{
			ans += tmp;
		}
	}
	cout << ans << endl;
	return 0;
}