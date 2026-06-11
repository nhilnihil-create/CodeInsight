#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>P;
	vector<int>M;

	for (int i = 0;i<N;++i) {
		int num;
		cin >> num;
		if (num > 0) {
			P.push_back(num);
		}
		else {
			M.push_back(-num);
		}
	}
	sort(M.begin(),M.end());
	if (0 == P.size()) {
		cout << M[K - 1];
		return 0;
	}
	if (0 ==M.size()) {
		cout << P[K - 1];
		return 0;
	}
	int ans = 1e9;
	for (int i = 0;i<=K;++i) {
		if (i<=P.size()  && (K-i)<=M.size()) {
			ans = min(ans ,P[i - 1]+M[K-i-1]+min(P[i - 1] , M[K - i - 1]));
		}
	}
	cout << ans << endl;
	return 0;
}