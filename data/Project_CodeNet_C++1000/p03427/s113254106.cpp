#include <iostream>
using namespace std;

int main() {
	string N, s;
	cin >> N;
	s = N.at(0);
	for (int i = 0; i < (int)N.size() - 1; i++) {
		s += '9';
	}
	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		ans += s.at(i) - '0';
	}
	if (s <= N) {
		cout << ans << endl;
	} else {
		cout << ans - 1 << endl;
	}
}