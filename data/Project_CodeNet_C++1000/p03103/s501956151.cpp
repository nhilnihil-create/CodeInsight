#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> > A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int use = min(M, A[i].second);
		M -= use;
		ans += (long long)(use) * A[i].first;
	}
	cout << ans << endl;
	return 0;
}