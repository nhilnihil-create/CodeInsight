#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int month = (S[5] - '0') * 10 + (S[6] - '0');
	if (4>=month) {
		cout << "Heisei" << endl;
	}
	else {
		cout << "TBD"<<endl;
	}
	return 0;
}