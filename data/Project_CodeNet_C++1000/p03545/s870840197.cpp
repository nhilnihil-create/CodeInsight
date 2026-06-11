#include<iostream>
#include<vector>
using namespace std;

int main() {
	string s; cin >> s;
	int ans;
	string op="+++";
	vector<int> num(4);
	for (int i = 0; i < 4; i++) {
		num[i] = s[i] - '0';
	}

	for (int bit = 0; 1 << 3;bit++) {
		ans = num[0];
		for (int i = 0; i < 3;i++) {
			if (bit & (1 << i)) {
				ans += num[i + 1];
				op[i] = '+';
			}
			else {
				ans -= num[i + 1];
				op[i] = '-';
			}
		}
		if (ans == 7) {
			break;
		}
	}
	for (int i = 0; i < 3; i++)cout << num[i] << op[i];
	cout << num[3] << "=7" << endl;

	return 0;
}
