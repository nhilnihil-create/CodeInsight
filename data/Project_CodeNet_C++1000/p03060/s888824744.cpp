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
#define double long long
using namespace std;
signed main() {
	int N;
	cin >> N;

	vector<int>V(N);
	vector<int>C(N);
	vector<int>A(N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
			cin >> V[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
			A[i]=V[i] - C[i];
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		if (A[i] > 0) {
			ans += A[i];
		}
	}
		cout << ans << endl;

}