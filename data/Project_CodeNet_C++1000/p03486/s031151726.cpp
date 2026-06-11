#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());

	bool flag = false;
	for (int i = 0; i < 100; i++) {
		if (s[i] < t[i]) {
			flag = true;
			break;
		}
		else if (s[i] > t[i]) break;
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}