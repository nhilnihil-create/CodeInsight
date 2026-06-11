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
	int64 nn;
	cin >> nn;
	vector<int64> aa(nn);
	stack<int64> ans;
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		auto ite = aa.begin();
		auto itf = aa.end();
		for(int64 jj = 1;jj <= aa.size();jj++)
		{
			if(*ite == jj)
			{
				itf = ite;
			}
			ite++;
		}
		if(itf == aa.end())
		{
			puts("-1");
			return 0;
		}
		ans.push(*itf);
		itf = aa.erase(itf);
	}
	while(!ans.empty())
	{
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}