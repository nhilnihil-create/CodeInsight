#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N);
	for (int i=0;i<N;i++) {cin >> A[i];}
	for (int i=0;i<N;i++) {cin >> B[i];}
	for (int i=0;i<N;i++) {cin >> C[i];}
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	sort(C.rbegin(), C.rend());

	vector<long long> val(N);
	for (int i=0;i<N;i++) {
		val[i] = C.rend()-upper_bound(C.rbegin(), C.rend(), B[i]);
	}

	vector<long long> ruiseki(N+1, 0LL);
	for (int i=0;i<N;i++) {
		ruiseki[i+1] = ruiseki[i]+val[i];
	}
	long long ans = 0LL;
	for (int i=0;i<N;i++) {
		int ind = B.rend()-upper_bound(B.rbegin(), B.rend(), A[i])-1;
		ans += ruiseki[ind+1];
	}
	cout << ans << endl;
}