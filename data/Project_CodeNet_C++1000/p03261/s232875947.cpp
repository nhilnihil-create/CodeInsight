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

int main() {
	int n;
	cin >> n;
	vector<string> vs(n, "");
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
	}
	unordered_set<string> us;
	for (int i = 0; i < n; i++) {
		if (us.find(vs[i]) != us.end()) {
			cout << "No" << endl;
			return 0;
		}
		if (i > 0 && vs[i][0] != vs[i - 1].back()) {
			cout << "No" << endl;
			return 0;
		}
		us.insert(vs[i]);
	}
	cout << "Yes" << endl;
}
