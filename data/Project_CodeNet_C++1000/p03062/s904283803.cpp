#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	long long N, A[MAX];
	long long sum = 0;
	cin >> N;
	long long cntnve = 0, cntpve = 0, cntzero = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0)
			cntnve++;
		else if (A[i] == 0)
			cntzero++;
		else
			cntpve++;
		A[i] = abs(A[i]);
		sum += A[i];
	}
	sort(A, A + N);
	if (cntzero > 0) {
		cout << sum << endl;
	} else if (cntnve % 2 == 0) {
		cout << sum << endl;
	} else if (cntnve % 2 == 1) {
		cout << sum - 2 * A[0] << endl;
	}
	return 0;
}
