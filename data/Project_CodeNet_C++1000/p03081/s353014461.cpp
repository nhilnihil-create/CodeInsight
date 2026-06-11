#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<pair<char, char> > command(q);
	for (int i = 0; i < q; ++i)
		cin >> command[i].first >> command[i].second;

	int ng = -1;
	int ok = n;
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		int pos = mid;
		bool left = false;
		for (auto c : command) {
			if (s[pos] == c.first) {
				if (c.second == 'L') --pos;
				else ++pos;
				if (pos < 0) {
					left = true;
					break;
				}
				if (pos >= s.size()) 
					break;
			}
		}
		if (left) ng = mid;
		else ok = mid;
	}
	int left_bound = ok;

	ng = -1;
	ok = n;
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		int pos = mid;
		bool right = false;
		for (auto c : command) {
			if (s[pos] == c.first) {
				if (c.second == 'L') --pos;
				else ++pos;
				if (pos < 0)
					break;
				if (pos >= s.size()) {
					right = true;
					break;
				}
			}
		}
		if (right) ok = mid;
		else ng = mid;
	}
	int right_bound = ok;

	cout << right_bound - left_bound << endl;
	return 0;
}