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
#include <cfloat>
#include <map>
using ll = long long;

//LLONG_MAX
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

int N;
int X[1000];
int Y[1000];

signed main()
{
	cin >> N;
	REP(i, N)
	{
		cin >> X[i] >> Y[i];
	}

	bool is_ki = ((abs(X[0]) + abs(Y[0])) % 2) == 1;

	REP(i, N)
	{
		if (((abs(X[i]) + abs(Y[i])) % 2) == (is_ki ? 0 : 1))
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	if (is_ki)
	{
		cout << 32 << endl;
	}
	else
	{
		cout << 33 << endl;
		REP(i, N)
		{
			X[i]++;
		}
		cout << 1 << " ";
	}

	int a[32];
	REP(i, 32)
	{
		a[i] = (int)pow(2, 31 - i);
		cout << a[i] << (i == 31 ? "" : " ");
	}
	cout << endl;

	REP(i, N)
	{
		if (!is_ki)
		{
			cout << "L";
		}

		int x = 0;
		int y = 0;

		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, 1, 0, -1};


		REP(j, 32)
		{
			int min_diff = LLONG_MAX;
			int min = -1;
			for (int d = 0; d < 4; d++)
			{
				int xx = a[j] * dx[d];
				int yy = a[j] * dy[d];
				int diff = abs(X[i] - (x + xx)) + abs(Y[i] - (y + yy));
				if (min_diff > diff)
				{
					min_diff = diff;
					min = d;
				}
			}

			switch (min)
			{
			case 0: cout << "R"; break;
			case 1: cout << "U"; break;
			case 2: cout << "L"; break;
			case 3: cout << "D"; break;
			}

			x += a[j] * dx[min];
			y += a[j] * dy[min];
		}

		cout << endl;
	}
}






