#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	print(s < t ? "Yes" : "No");
}