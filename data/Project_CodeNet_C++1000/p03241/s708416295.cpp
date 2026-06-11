#include "bits/stdc++.h"
using namespace std;
typedef pair<long long, long long> P;
int main() {
	long long N, M; cin >> N >> M;
	vector<long long>num;
	for (long long i = 1; i <= sqrt(M); i++) {
		if (M % i == 0) {
			if (i == M / i)num.push_back(i);
			else {
				num.push_back(i);
				num.push_back(M / i);
			}
		}
	}
	sort(num.begin(), num.end());
	long long ans = 0;
	for (long long i = 0; i < num.size(); i++) {
		if ((M - num.at(i) * (N - 1)) % num.at(i) == 0 && (M - num.at(i) * (N - 1)) > 0) ans = num.at(i);
	}
	cout << ans << endl;
}