#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x, T a, T b) { return a <= x&&x <= b; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
int ROUND(double x) { return (int)(x + 0.5); }
bool ISINT(double x) { return fabs(ROUND(x) - x) <= EPS; }
bool ISEQUAL(double x, double y) { return fabs(x - y) <= EPS*max(1.0, max(fabs(x), fabs(y))); }
double SQSUM(double x, double y) { return x*x + y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;


int main()
{
	int q;
	cin >> q;
	for (int query = 0; query < q; ++query)
	{
		ll a, b;
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}

		ll ans = 0;

		if (a == 1 && b == 1)
		{
			ans = 0;
		}
		else
		{

			ll c = a*b - 1;
			ll x = sqrt(c) + 100;

			while (x*x>c)
			{
				x--;
			}






			ans = x * 2;

			if (x == c / x)
			{
				ans--;
			}

			if (x >= a)
			{
				ans--;
			}

			// BEGIN CUT HERE
//			cerr << "a=" << a << " b=" << b << " c=" << c << " x=" << x << " c/x=" << c/x << " ans=" << ans << endl;
			// END CUT HERE



		}




		cout << ans << endl;
	}




	return 0;
}
