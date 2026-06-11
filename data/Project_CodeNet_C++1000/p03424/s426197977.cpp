#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 0;
	char input;
	int count = 0;
	while (i < N) {
		cin >> input;
		if (input == 'Y') {
			count++;
		}
		i++;
	}
	if (count > 0) {
		cout << "Four" << endl;
	}else {
		cout << "Three" << endl;
	}
}