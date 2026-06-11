#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	int n;
	cin >> n;
	vector<pair<long long int, long long int> > v;
	for (int i = 0; i < n; i++) {
		long long int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a + b, a));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	long long int t = 0, a = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			t += v[i].second;
		else
			a += v[i].first - v[i].second;
	}
	cout << t - a << endl;
}