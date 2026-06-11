#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//5000000000000000

int main() {
	string s;
	cin >> s;
	unsigned long long K;
	cin >> K;

	bool flags = false;
	for (int i = 0; i < K; ++i) {
		if (s[i] != '1') {
			flags = true;
			break;
		}
	}

	for (int i = 0; i < s.length() && flags; ++i) {
		if (s[i] != '1') {
			cout << s[i] << endl;
			return 0;
		}
	}

	cout << 1 << endl;
	return 0;
}