#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, a;
	int total = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (a % 2 != 1) {
			a = a / 2;
			total++;
		}
	}
	cout << total << endl;
}