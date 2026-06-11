#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string w[n];
	int l[n];
	int cun = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		l[i] = w[i].length();
		if (i != 0) {
			if (w[i - 1][l[i - 1] - 1] != w[i][0]) {
				cun++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] == w[j]) {
				cun++;
			}
		}
	}
	if (cun == 0) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}
}