#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int coin = 0;
	for (int i = 0; i < 2; i++) {
		if (A >= B) {
			coin += A;
			A--;
		}
		else {
			coin += B;
			B--;
		}
	}
	cout << coin << endl;
	return 0;
}