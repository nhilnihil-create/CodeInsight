#include <bits/stdc++.h>
using namespace std;
int f(int x, int y, int z) {
	return x * x + y * y + z * z + x * y + y * z + z * x;
}

int main() {
	string s,tmp;
	cin >> s;
	int n, tmpans = 0;
	bool flag = 1;
	n = s.size();
	vector<int> ans(n + 1);
	for (int i = 0; i < n; i++) {
		tmpans = 0;
		for (int j = 0; j < n - i; j++) {
			tmp = s.substr(j, i+1);
			flag = 1;
			for (char c : tmp) {
				if (c != 'A' && c != 'T' && c != 'G' && c != 'C') {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				tmpans++;
			}
		}
		ans.at(i) = tmpans;
	}
	for (int i = 0; i < n; i++) {
		if (ans.at(i) != 0) {
			tmpans = i + 1;
		}
	}
	cout << tmpans << endl;
}