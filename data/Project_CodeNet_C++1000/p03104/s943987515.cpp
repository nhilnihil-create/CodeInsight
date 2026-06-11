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
	int64 aa, bb, ans;
	cin >> aa >> bb;
	if(((int64)(bb / 2) - (int64)(aa / 2)) % 2 == 0)
	{
		ans = 1;
	}
	else
	{
		ans = 0;
	}
	if(aa % 2 == 1)
	{
		ans ^= aa;
	}
	else
	{
		ans ^= 1;
	}
	if(bb % 2 == 0)
	{
		ans ^= bb;
	}
	else
	{
		ans ^= 1;
	}
	cout << ans << endl;
	return 0;
}