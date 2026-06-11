#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

double getpow(double x, int n)
{
	if(n == 0) return 1.0;
	double tmp = getpow(x, n / 2);
	if(n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * x;
}

int main()
{
	double n, m, d;
	cin >> n >> m >> d;
	double ans;
	if(d == 0){
		ans = 1.0 / n * (m - 1.0);
	} else {
		double tmp = 2.0 * (n - d) / (n * n);
		ans =tmp * (m - 1.0);
	}
	printf("%.10f\n", ans);
}
