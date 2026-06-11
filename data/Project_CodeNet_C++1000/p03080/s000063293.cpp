#include "bits/stdc++.h"
using namespace std;


int main() {

	int N;
	string S;
	int counter_R = 0;
	int counter_B = 0;
	string R = "R";
	string B = "B";

	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++) {
		if (S[i] == R[0]) counter_R++;
		if (S[i] == B[0]) counter_B++;
	}

	if (counter_R > counter_B) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	return 0;

}
