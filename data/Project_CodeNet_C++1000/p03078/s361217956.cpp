#include "bits/stdc++.h"
using namespace std;
int main() {
	long long X, Y, Z, K; cin >> X >> Y >> Z >> K;
	vector<long long>A(X), B(Y), C(Z);
	for (long long i = 0; i < X; i++) {
		cin >> A.at(i);
	}
	for (long long i = 0; i < Y; i++) {
		cin >> B.at(i);
	}
	for (long long i = 0; i < Z; i++) {
		cin >> C.at(i);
	}
	sort(A.begin(), A.end(), greater<long long>());
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());
	vector<long long>ans;
	for (long long i = 0; i < X; i++) {
		for (long long j = 0; j < Y; j++) {
			ans.push_back(A.at(i) + B.at(j));
		}
	}
	sort(ans.begin(), ans.end(), greater<long long>());
	vector<long long>sum;
	for (long long i = 0; i < min(K, (long long)ans.size()); i++) {
		sum.push_back(ans.at(i));
	}
	vector<long long>out;
	for (long long i = 0; i < min(K, (long long)ans.size()); i++) {
		for (long long j = 0; j < min(Z, K); j++) {
			out.push_back(sum.at(i) + C.at(j));
		}
	}
	sort(out.begin(), out.end(), greater<long long>());
	for (long long i = 0; i < K; i++) {
		cout << out.at(i) << endl;
	}
}