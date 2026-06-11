#include <iostream>
#include<algorithm>

using namespace std;

int N;

long long int A[200005], B[200005];

int main(void) {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; cin >> B[i];
	}

	int I; long long int Bmin = 100000000000;
	long long int sum_LARGE = 0; for (int i = 1; i <= N; i++) { sum_LARGE += abs(A[i] - B[i]); }
	for (int i = 1; i <= N; i++) {
		if (A[i] - B[i] > 0 && B[i] < Bmin) { I = i; Bmin = B[i]; }
	}

	long long int sum_A = 0;
	for (int i = 1; i <= N; i++) {
		if (i == I) { continue; }
		sum_A += A[i];
	}

	long long int ans;
	if (sum_LARGE == 0) {
		ans = 0;
	}
	else {
		ans = sum_A +A[I]-B[I];
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}