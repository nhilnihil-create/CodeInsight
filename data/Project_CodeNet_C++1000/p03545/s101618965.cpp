#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;


int main() {
	string s;
	cin >> s;
	vector<int> x(4);
	rep(i, 4) {
		x[i] = s[i] - '0';
	}

	string ans;
	rep(j, 8) {
		//長さ 3 の bitset を定義する
		bitset<3> bits(j);
		int sum = x[0];
		for (int i = 1; i < 4; i++) {
			if (bits[i - 1])sum += x[i];
			else sum -= x[i];
		}
		if (sum == 7) {
			ans = to_string(x[0]);
			for (int i = 1; i < 4; i++) {
				if (bits[i - 1])ans += '+';
				else ans += '-';
				ans += to_string(x[i]);
			}
			ans += "=7\n";
			break;
		}
	}
	cout << ans;
	return 0;
}

