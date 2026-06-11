#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N >> s;
	int red = 0;
	int blue = 0;
	for (int i = 0; i < N; i++) {
		if (s.at(i) == 'R') {
			red++;
		}
		else {
			blue++;
		}
	}
	if (red > blue) {
		cout << "Yes" << endl;
	}
	else if (red <= blue) {
		cout << "No" << endl;
	}
}
