#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <list>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int even = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
		if (a.at(i) % 2 == 0) {
			even++;
		}
	}

	cout << pow(3, n) - pow(2, even) << endl;

	return 0;
}