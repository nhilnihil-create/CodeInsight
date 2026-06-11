#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n; cin >> n;
	int cnt = 0, a = 0, b = 0, ab = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		bool f = false;
		for (int j = 0; j < s.size() - 1; ++j)
			if (s.substr(j, 2) == "AB") ++cnt;
		if (s.back() == 'A') ++a, f = true;
		if (s.front() == 'B') ++b;
		else f = false;
		if (f) ++ab;
	}
	cout << max(0, cnt + min(a, b) - (ab && ab == a && ab == b ? 1 : 0)) << endl;

	return 0;
}