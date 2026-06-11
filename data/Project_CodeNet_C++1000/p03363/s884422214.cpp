#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N; cin >> N;
	vector<long long>A(N), sum(N + 1, 0);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
		sum.at(i + 1) = sum.at(i) + A.at(i);
	}
	sort(sum.begin(), sum.end());
	vector<long long>same;
	long long num = 1, to = sum.at(0);
	for (long long i = 1; i <= N; i++) {
		if (sum.at(i) == to) num++;
		else {
			same.push_back(num);
			num = 1;
			to = sum.at(i);
		}
	}
	same.push_back(num);
	long long ans = 0;
	for (long long i = 0; i < same.size(); i++) {
		ans += same.at(i) * (same.at(i) - 1) / 2;
	}
	cout << ans << endl;
}