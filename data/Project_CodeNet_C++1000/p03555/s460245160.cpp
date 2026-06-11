#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	vector<string> v(2);
	cin >> v[0] >> v[1];

	reverse(v[1].begin(), v[1].end());
	cout << (v[0] == v[1] ? "YES" : "NO") << endl;
	return 0;
}
