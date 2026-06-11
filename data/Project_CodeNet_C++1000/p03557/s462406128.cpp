#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i];
	}
	vector<int>B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int>C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end()); 
	sort(C.begin(), C.end());
	long long ans = 0;	
	for (int i = 0; i < N; ++i) {
		long long x = lower_bound(A.begin(), A.end(), B[i])- A.begin();
		long long y = C.end()- lower_bound(C.begin(), C.end(), B[i]+1); 
		//cout << x <<"_"<< y << endl;
		ans += x * y;
	}
	cout << ans << endl;
	return 0;
}
