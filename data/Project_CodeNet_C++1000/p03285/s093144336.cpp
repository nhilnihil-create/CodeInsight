#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 100; i++) {
		if (N > 0) {
			if (N % 4 == 0 || N % 7 == 0) {
				cout << "Yes" << endl;
				break;
			}
			else {
				N -= 4;
			}
		}
		else {
			cout << "No" << endl;
			break;
		}
	}
}
