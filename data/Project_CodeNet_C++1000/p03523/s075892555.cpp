#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	string T = "AKIHABARA";
	bool ok = false;
	for (int i = 0; i < 1 << 9; ++i) {
		bool valid = true;
		string tar;
		for (int j = 0; j < 9; ++j) {
			if ((i >> j) & 1) {
				tar += T[j];
			}
			else if (T[j] != 'A') {
				valid = false;
			}
		}
		if (valid && tar == s) {
			ok = true;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}