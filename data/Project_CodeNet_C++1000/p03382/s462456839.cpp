#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <unordered_map>
#include <map>
#include <set>
#include <array>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int p, q;
	p = *max_element(a.begin(), a.end());
	a.erase(max_element(a.begin(), a.end()));
	if (p % 2 == 0) {
		int tmp = p / 2;
		int r = INF;
		for (int i = 0; i < a.size(); i++) {
			if (r > abs(a[i] - tmp)) {
				r = abs(a[i] - tmp);
				q = a[i];
			}
		}
	}
	else {
		int tmp[2] = { p / 2, p / 2 + 1 };
		int r = INF;
		for (int i = 0; i < a.size(); i++) {
			if (r > abs(a[i] - tmp[0])) {
				r = abs(a[i] - tmp[0]);
				q = a[i];
			}
			if (r > abs(a[i] - tmp[1])) {
				r = abs(a[i] - tmp[1]);
				q = a[i];
			}
		}
	}
	cout << p << " " << q << endl;
	return 0;
}