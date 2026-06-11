#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int N;
	cin >> N;

	int A;
	cin >> A;
	int minA = A;
	int maxA = A;
	for (int i = 1; i < N; i++) {
		cin >> A;
		if (A < minA) {
			minA = A;
		}
		else if (A > maxA) {
			maxA = A;
		}
	}

	cout << maxA - minA << endl;

	return 0;
}

