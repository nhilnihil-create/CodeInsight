#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>


using namespace std;



int main() {

	int A, B;
	string S;
	bool ans = true;

	cin >> A >> B;
	cin >> S;
	
	for (int i = 0; i < A + B + 1; i++) {
		if (S[i] != '-' && i == A) ans = false;
		if (S[i] == '-' && i != A) ans = false;
	}
	if (ans) cout << "Yes";
	else cout << "No";

	return 0;

}