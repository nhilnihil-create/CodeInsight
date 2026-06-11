#include <iostream>
#include <string>
using namespace std;

int ans(string s) {
	if (s.length() == 1) return s[0] - '0';
	if (s[0] == '9' && s[1] != '9') return 9 * s.length() - 1;
	if (s[0] == '9' && s[1] == '9') return 9 + ans(s.substr(1, s.length() - 1));
	if (s[0] != '9' && s[1] == '9') return s[0] - '0' + ans(s.substr(1, s.length() - 1));
	if (s[0] != '9' && s[1] != '9') return s[0] - '0' - 1 + 9 * (s.length() - 1);
}

int main() {
	string N;
	cin >> N;
	cout << ans(N) << endl;
}