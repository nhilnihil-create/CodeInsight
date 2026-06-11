#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 0;
	for (int i = 1; i < N + 1; i++) {
		if (i * i <= N) {
			total = i * i;
		}
		else {
			break;
		}
	}
	cout << total << endl;
}
