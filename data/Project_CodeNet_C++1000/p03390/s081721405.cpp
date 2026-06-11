#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <deque>
#include <bitset>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) v.erase(remove(v.begin(), v.end(), a), v.end())
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i) = 0; (i) <= (n); (i)++)
using namespace std;

int Q;

int func(int a, int b)
{
	int sum = 0;

	sum += (a - 1) * 2;

	int min = 0;
	int max = (b - 1 - a) + 1;
	while (true)
	{
		int x = ((max - min) / 2) + min;

		if (max - min <= 1)
		{
			sum += b - 1 - a - x;
			return sum;
		}

		int n = MAX(0, (((a + 1) + (b - 1 - x)) / 2) - (a + 1));
		int k = (a + 1 + n) * (b - 1 - n - x);

		if (k >= a * b)
		{
			min = x;
		}
		else
		{
			max = x;
		}
	}
}

signed main()
{
	cin >> Q;
	REP(i, Q)
	{
		int a_, b_;
		cin >> a_ >> b_;

		int a = MIN(a_, b_);
		int b = MAX(a_, b_);

		if (a == b)
		{
			cout << (2 * a - 2) << endl;
		}
		else if (a == b - 1)
		{
			cout << (2 * a - 2) << endl;
		}
		else
		{
			cout << func(a, b) << endl;
		}
	}
}
