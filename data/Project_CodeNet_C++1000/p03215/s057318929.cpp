#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, K;
ll A[1000];
ll ruisekiwa[1001];
vector<ll> candidate;
vector<ll> tmp;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> A[i], ruisekiwa[i + 1] = ruisekiwa[i] + A[i];
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)candidate.push_back(ruisekiwa[j + 1] - ruisekiwa[i]);
	}

	ll ans = 0;
	int cnt = 0;
	ll MSB = 0;
	ll M = (*max_element(candidate.begin(), candidate.end()));
	while ((1LL << MSB) <= M)MSB++;
	MSB--;

	for (; MSB >= 0; MSB--) {
		for (int i = 0; i < candidate.size(); i++) {
			if (candidate[i] & (1LL << MSB)) {
				cnt++;
				tmp.push_back(candidate[i]);
			}
		}
		if (cnt >= K) {
			ans += (1LL << MSB);
			candidate = tmp;
		}
		tmp.clear();
		cnt = 0;
	}
	cout << ans << endl;
	return 0;
}
