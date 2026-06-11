#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<long, long>> AB(N);
	for (pair<long, long>& i : AB) cin >> i.first >> i.second;
	sort(AB.begin(), AB.end(), [](pair<long, long>& a, pair<long, long>& b) { return b.first + b.second < a.first + a.second; });
	long ans = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2) ans -= AB[i].second;
		else ans += AB[i].first;
	}
	cout << ans;
}