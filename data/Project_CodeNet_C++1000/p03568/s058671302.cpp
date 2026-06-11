#include <iostream>
#include <cmath>
using namespace std;

// all triplets - all odd triplets

int main() {
	int N, odd = 1;;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp % 2 == 0) {
			odd *= 2;
		} else {
			odd *= 1;
		}
	}
	int ans = pow(3, N);
	cout << ans - odd << endl;
}
