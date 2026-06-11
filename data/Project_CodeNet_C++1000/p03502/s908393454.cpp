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
	string N;
	cin >> N;
	int n = stoi(N);
	int A = 0;

	for (int i = 0; i < N.size(); i++) {
		 A += N[i]-'0';
	}
	if (n % A == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}