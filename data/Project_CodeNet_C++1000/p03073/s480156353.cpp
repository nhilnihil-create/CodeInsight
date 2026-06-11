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
	string a;
	cin >> a;
	ll x = 0;
	ll y = 0;
	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0) {//最初が白パターン
			if (a[i] == '0') {
				x++;
			}
		}
		else {
			if (a[i] == '1') {
				x++;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0) {//最初が黒パターン
			if (a[i] == '1') {
				y++;
			}
		}
		else {
			if (a[i] == '0') {
				y++;
			}
		}
	}
	cout << min(x, y) << endl;
}