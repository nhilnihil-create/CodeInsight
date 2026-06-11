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

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, tmp;
	cin >> nn;
	vector<int64> memo(nn + 1);
	for(int64 ii = 0;ii <= nn;ii++)
	{
		memo[ii] = ii;
	}
	tmp = 1;
	while(tmp <= nn)
	{
		tmp *= 6;
		for(int64 jj = 0;jj <= nn;jj++)
		{
			if(jj + tmp <= nn)
			{
				if(memo[jj + tmp] > memo[jj] + 1)
				{
					memo[jj + tmp] = memo[jj] + 1;
				}
			}
		}
	}
	tmp = 1;
	while(tmp <= nn)
	{
		tmp *= 9;
		for(int64 jj = 0;jj <= nn;jj++)
		{
			if(jj + tmp <= nn)
			{
				if(memo[jj + tmp] > memo[jj] + 1)
				{
					memo[jj + tmp] = memo[jj] + 1;
				}
			}
		}
	}
	cout << memo[nn] << endl;
	return 0;
}
