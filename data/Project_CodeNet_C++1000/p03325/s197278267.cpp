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
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using ii = vector<vector<long long>>;
int main() {
	ll a;
	cin >> a;
	ll count = 0;
	vl x(a);
	for (int i = 0; i < a; i++) {
		cin >> x[i];
	}
	for (ll i = 0; i < a; i++) {
		for (ll j = 0; j < 100; j++) {
			if (x[i] % 2 == 1) {
				break;
			}
			else {
				count++;
				x[i] = x[i] / 2;
			}
		}
	}
	cout << count << endl;
}