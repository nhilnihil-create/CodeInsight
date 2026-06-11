#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <tuple>
#include <regex>
#include <map>

using namespace std;
using ull = unsigned long long;

int main() {
	string S;
	cin >> S;

	if (S.length() == 3) {
		reverse(begin(S), end(S));
	}
	cout << S << endl;

	return 0;
}

