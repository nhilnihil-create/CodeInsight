#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B,C,D;
	cin >> A >> B >> C >> D;
	if (abs(A-C)<=D) {
		cout << "Yes"<< endl;
		return 0;
	}
	if ((abs(A-B)<=D)&&(abs(B-C)<=D)) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No"<<endl;
	return 0;
}