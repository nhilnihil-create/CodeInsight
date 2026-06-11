#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string S;
	cin >> S;

	int x = 0;
	for (int i = 0; i < S.size(); i++) {

		if (S[i] == '1') {
			x++;
		}
	}
	cout << x << endl;

}