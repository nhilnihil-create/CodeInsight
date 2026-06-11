#include <iostream>
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
#include <math.h>
#define int long long
using namespace std;
signed main() {
	int N; cin >> N;
	int D = 0;
	vector<int>vec(N);
	for (int X = 0; X < N; X++) {
		cin >> vec[X];
		for (int Y = 0; Y < 30; Y++) {
			if (vec[X] % 2 == 0) {
				vec[X] /= 2;
				D++;
			}
		}
	}
	cout << D << endl;
}
