#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	cout << (s == "abc" ? "Yes" : "No") << endl;
	return 0;
}
