#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string S;
	cin >> S;
	int rec = 0;
	if (S[0] == 'A' && S[S.length()-1] > 96) {
		if (S[1] < 96) {
			rec += 2;
		}
		else {
			for (int i = 2; i < S.length() - 1; i++) {
				if (S[i] == 'C') {
					rec++;
				}
				if (S[i] < 96) {
					rec += 2;
				}
			}
		}
	}
	else {
		rec += 2;
	}
	if (rec == 3) {
		cout << "AC" << endl;
	}
	else {
		cout << "WA" << endl;
	}
	return 0;
}