#include "bits/stdc++.h"
using namespace std;


int main() {
	string S, T;
	cin >> S >> T;
	T += T;
	if (-1 != T.find(S)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}