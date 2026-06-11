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
	int64 nn, ans = 0, frb = 0, baa = 0, ba = 0;
	cin >> nn;
	string ss;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> ss;
		for(int64 jj = 0;jj < ss.length() - 1;jj++)
		{
			if(ss.substr(jj, 2) == "AB")
			{
				ans++;
			}
		}
		if(ss[0] == 'B' && ss[ss.length() - 1] == 'A')
		{
			ba++;
		}
		else if(ss[0] == 'B')
		{
			frb++;
		}
		else if(ss[ss.length() - 1] == 'A')
		{
			baa++;
		}
	}
	int64 tmp = frb + baa;
	if(tmp == 0)
	{
		cout << (ans + (int64)max((int64)0, ba - 1)) << endl;
	}
	else
	{
		if(ba == 0)
		{
			cout << (ans + (int64)min(frb, baa)) << endl;
		}
		else
		{
			cout << (ans + ba + (int64)min(frb, baa)) << endl;
		}
	}
	return 0;
}