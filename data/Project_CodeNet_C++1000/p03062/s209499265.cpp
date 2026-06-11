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
	int64 nn, mai = 0, sum = 0, tmp, mina = 100000000000000;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		tmp = aa[ii];
		if(tmp < 0)
		{
			mai++;
			tmp *= (-1);
		}
		sum += tmp;
		mina = min(mina, tmp);
	}
	if(mai % 2 == 0)
	{
		cout << sum << endl;
	}
	else
	{
		cout << (sum - 2 * mina) << endl;
	}
	return 0;
}