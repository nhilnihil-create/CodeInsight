#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N , Z , W;
	cin >> N >> Z >> W;
	vector<long long>A(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i];
	}
	if (1!=N) {
		cout << max(abs(W - A[N - 1]), abs(A[N - 1] - A[N - 2])) << endl;
	}
	else {
		cout << abs(W - A[N - 1]) << endl;
	}
	return 0;
}