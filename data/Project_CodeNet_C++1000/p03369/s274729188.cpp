#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string S;
	cin >> S;

	int x = 700;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'o') {
			x += 100;
		}
	}
	cout << x << endl;
}