#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

LL calc(vector<LL>& A, LL b, LL N) {
	LL l = 0, r = N - 1;
	if (A[l] > b) {
		return 0;
	}
	else if (A[r] <= b) {
		return N;
	}


	while (true) {
		LL mid = (l + r) / 2;
		if (r - l <= 1) {
			return l + 1;
		}
		if (A[mid] < b) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return 0;
}


int main() {
	LL N;
	cin >> N;
	vector<LL> A(N), B(N), C(N);
	for (LL i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (LL i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (LL i = 0; i < N; i++) {
		cin >> C[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());



	vector<LL> sumB(N, 0);
	for (LL i = 0; i < N; i++) {
		auto itr = lower_bound(A.begin(), A.end(), B[i]);
		LL num = itr - A.begin();	// B[i]より小さいの数字の個数
		sumB[i] = num;
		if (i > 0) {
			sumB[i] += sumB[i - 1];
		}
	}

	LL ans = 0;
	for (LL i = 0; i < N; i++) {

		LL num = lower_bound(B.begin(), B.end(), C[i]) - B.begin(); // C[i] より小さい数字の個数
		if (num > 0) {
			ans += sumB[num - 1];

		}
	}
	cout << ans << endl;
	return 0;
}
