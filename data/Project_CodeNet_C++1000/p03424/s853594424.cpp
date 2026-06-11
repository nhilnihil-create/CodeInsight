#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;
	int flag = 0;
	char arale;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arale;
		if (arale == 'Y') {
			flag++;
		}
	}
	if (flag > 0) {
		cout << "Four" << endl;
	} else {
		cout << "Three" << endl;
	}
}
