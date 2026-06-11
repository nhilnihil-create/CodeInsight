#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i > 0 && v[i] == v[i - 1]) {
			v[i] = -1;
			res++;
		}
	}
	cout << res << endl;
}




