#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N;
	cin >> N;
	vector<long long>A(N), B(N);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	long long ans = 0, num = 0;
	vector<long long>sum;
	for (long long i = 0; i < N; i++) {
		cin >> B.at(i);
		if (A.at(i) >= B.at(i)) sum.push_back(A.at(i) - B.at(i));
		else {
			num += (B.at(i) - A.at(i));
			ans++;
		}
	}
	if (sum.size() == N) {
		cout << 0 << endl;
		return 0;
	}
	sort(sum.begin(), sum.end(), greater<int>());
	for (long long i = 0; i < sum.size(); i++) {
		if (sum.at(i) >= num) {
			cout << ans + 1 << endl;
			return 0;
		}
		else {
			num -= sum.at(i);
			ans++;
		}
	}
	cout << -1 << endl;
 }