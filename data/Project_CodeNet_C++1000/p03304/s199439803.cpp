#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	ll n, m, d;
	cin >> n >> m >> d;
	double ans = ((d > 0 ? 2.0 : 1.0) * (n-d) / n) *  (m-1) / (1.0*n);
	printf("%.10f\n", ans);
	return 0;
}