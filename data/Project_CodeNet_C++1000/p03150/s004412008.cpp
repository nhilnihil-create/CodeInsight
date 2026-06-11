#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S == "keyence") {
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 0; i < S.length(); i++) {
		for (int j = 1; i + j < S.length(); j++) {
			string T = S;
			T.erase(i, j);
			if (T == "keyence") {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}