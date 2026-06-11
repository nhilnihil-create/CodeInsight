#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		ans *= (A % 2 == 0 ? 2 : 1);
	}
	cout << (int)pow(3, N) - ans << endl;
}