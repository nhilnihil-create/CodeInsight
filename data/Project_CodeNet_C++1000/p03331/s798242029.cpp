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
	string s = to_string(n);
	int res = 0;
	for (auto ss : s) {
		res += ss - '0';
	}
	if (res == 1) {
		cout << 10 << endl;
	} else {
		cout << res << endl;
	}
}




