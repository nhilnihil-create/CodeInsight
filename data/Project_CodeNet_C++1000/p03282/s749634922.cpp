#include <iostream>
using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;

	int i = 0;
	int ans = 1;
	while (i < k) {
		if (s.at(i) - '0' == 1) {
			i++;
		} else {
			ans = s.at(i) - '0';
			break;
		}
	}
	cout << ans << endl;
	return 0;
}