#include "omp.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <random>
#include <bitset>
#include <unordered_set>
#include <cassert>
#include <list>
#include <functional>


using namespace std;

typedef long long ll;
typedef long double ld;


const int sze = 1 << 15, INF = 1e9 + 10;


pair<int, int> ans;
ld cnt = 0;


signed main()
{
	int n;
	cin >> n;

	vector<int> values(n);

	for (int i = 0; i < n; ++i)
		cin >> values[i];

	sort(values.begin(), values.end());

	int l = -1, r = n;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;

		if (values[m] * 2 >= values[n - 1])
			r = m;
		else
			l = m;
	}

	if (l == -1)
		cout << values[n - 1] << ' ' << values[r];
	else if (r == n)
		cout << values[n - 1] << ' ' << values[l];
	else
	{
		if (values[n - 1] - values[r] > values[l])
			cout << values[n - 1] << ' ' << values[r];
		else
			cout << values[n - 1] << ' ' << values[l];
	}

	return 0;
}