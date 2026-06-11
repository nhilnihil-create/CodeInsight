#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int num[3] = { 0,0,0 };
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		num[(p > A) + (p > B)]++;
	}
	cout << min({ num[0], num[1], num[2] }) << endl;
}
