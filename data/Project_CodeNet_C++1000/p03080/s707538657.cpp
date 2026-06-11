#include<iostream>

using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int red = 0;
	int blue = 0;
	for (int i = 0; i < N; i++) {
		if (S.at(i) == 'R') {
			red++;
		}
		else {
			blue++;
		}
	}

	if (red > blue) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}
