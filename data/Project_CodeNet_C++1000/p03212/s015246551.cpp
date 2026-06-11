#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

vector<string> f(int d, int n, int& res) {
	if (d == 1) {
		return vector<string> {"3", "5", "7"};
	}
	vector<string> vs, ret = f(d - 1, n, res);
	for (auto s : ret) {
		vs.push_back(s);
		vs.back().push_back('3');
		vs.push_back(s);
		vs.back().push_back('5');
		vs.push_back(s);
		vs.back().push_back('7');
	}
	for (auto s : vs) {
		int d3 = 0, d5 = 0, d7 = 0;
		for (auto ss : s) {
			if (ss == '3') d3++;
			if (ss == '5') d5++;
			if (ss == '7') d7++;
		}
		if (d3 && d5 && d7 && stoll(s) <= n) res++;
	}
	return vs;
}

int main() {
	int n;
	cin >> n;
	int res = 0;
	int l = to_string(n).size();
		f(l, n, res);
	
	cout << res << endl;
}
