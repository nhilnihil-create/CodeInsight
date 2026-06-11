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
	bool A = false;

	vector<char>S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		if (S[i] == 'Y') {
			A = true;
		}
	}
	if (A == true) {
		cout << "Four" << endl;
	}
	else {
		cout << "Three" << endl;
	}


}