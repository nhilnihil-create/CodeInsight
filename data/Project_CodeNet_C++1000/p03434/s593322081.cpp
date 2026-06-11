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
	int64 nn, aa = 0, bb = 0;
	cin >> nn;
	vector<int64> memo(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> memo[ii];
	}
	sort(memo.begin(), memo.end());
	reverse(memo.begin(), memo.end());
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(ii % 2 == 0)
		{
			aa += memo[ii];
		}
		else
		{
			bb += memo[ii];
		}
	}
	cout << (aa - bb) << endl;
	return 0;
}