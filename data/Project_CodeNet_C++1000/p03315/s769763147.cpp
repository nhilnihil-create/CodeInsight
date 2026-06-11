#include<iostream>
#include<vector>

using namespace std;

int main() {
	string S;
	cin >> S;

	int num = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '+') {
			num = num + 1;
		}
		else {
			num = num - 1;
		}
	}

	cout << num << endl;
}
