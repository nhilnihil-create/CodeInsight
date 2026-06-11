#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define int long long
using namespace std;
signed main() {
	int N;
	cin >> N;
	int A = 0;
	vector<int>p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		A += p[i];
	}
	sort(p.begin(), p.end()); // {1, 2, 2, 5}
	reverse(p.begin(), p.end());
	cout << A - p[0] / 2 << endl;
}