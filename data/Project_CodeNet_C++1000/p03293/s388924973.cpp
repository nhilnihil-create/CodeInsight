#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string S, T;
	cin >> S >> T;
	int rec = 0;
	for (int i = 0; i < S.length(); i++) {
		char s = S[0];
		for (int j = 0; j < S.length() - 1; j++) {
			S[j] = S[j + 1];
		}
		S[S.length() - 1] = s;
		if (S == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}