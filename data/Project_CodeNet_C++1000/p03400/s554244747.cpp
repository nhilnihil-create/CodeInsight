#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, D, X;
	cin >> N >> D >> X;
	for (int i = 0;i<N;++i) {
		int A;
		cin >> A;
		X += (D+A-1)/A;
	}
	cout << X << endl;
	return 0;
}
