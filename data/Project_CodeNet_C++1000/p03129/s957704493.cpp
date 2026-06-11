#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int N, K;

	cin >> N >> K;

	int M;

	if (N % 2 == 0) {
		M = N / 2 ;
	}
	else {
		M = (N / 2) + 1;
	}

	if (M >= K) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}