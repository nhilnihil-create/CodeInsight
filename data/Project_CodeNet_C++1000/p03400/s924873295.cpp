#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, D, X;
	cin >> N >> D >> X;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		X += D % a == 0 ? D / a : D / a + 1;
	}
	cout << X << endl;
	return 0;
}
