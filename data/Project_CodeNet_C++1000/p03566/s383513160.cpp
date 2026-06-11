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

int main()
{
	int n;
	cin >> n;
	double t[110] = {};
	double v[110] = {};
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		t[i] += t[i - 1];
	}
	t[n + 1] = t[n];
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	double ans = 0.0;
	double beforev = 0.0;
	for(double i = 0.5; i <= t[n]; i += 0.5)
	{
		double nowv = 200000.0;
		for(int j = 0; j <= n + 1; j++){
			double tmpv = 0.0;
			if(j == 0) tmpv = v[j] + i;
			else if(i < t[j - 1]) tmpv = v[j] + t[j - 1] - i;
			else if(i <= t[j]) tmpv = v[j];
			else tmpv = v[j] + i - t[j];
			nowv = min(nowv, tmpv);
		}
		ans += (beforev + nowv) * 0.5 / 2.0;
		beforev = nowv;
	}
	printf("%.10f\n", ans);
}