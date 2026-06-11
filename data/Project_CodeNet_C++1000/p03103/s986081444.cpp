#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<long long int, long long int>>P(N);
	for (int i = 0; i < N; i++) {
		long long int a, b;
		cin >> a >> b;
		P[i] = make_pair(a, b);
	}
	sort(P.begin(), P.end());
	long long int ans = 0;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (k + P[i].second > M) {
			ans += (P[i].first * (M - k));
			break;
		}
		ans += (P[i].first) * (P[i].second);
		k += P[i].second;

	}
	cout << ans << endl;
 	return 0;
}