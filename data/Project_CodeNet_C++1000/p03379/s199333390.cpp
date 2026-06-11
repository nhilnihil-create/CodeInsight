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
using namespace std;

int main()
{
	int64 nn, ll, hh;
	cin >> nn;
	vector<int64> xx(nn), yy(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> xx[ii];
		yy[ii] = xx[ii];
	}
	sort(yy.begin(), yy.end());
	ll = yy[nn / 2 - 1];
	hh = yy[nn / 2];
	for(int64 ii = 0;ii < nn;ii++)
	{
		if(xx[ii] <= ll)
		{
			cout << hh << endl;
		}
		else
		{
			cout << ll << endl;
		}
	}
	return 0;
}