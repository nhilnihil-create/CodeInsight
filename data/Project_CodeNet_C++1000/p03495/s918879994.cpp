
// C - Not so Diverse

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

map<int, int> num_to_cnt;
vector<int> cnt;

int main() {
	int N, K;
	cin >> N >> K;

	int A;
	for (int i=0; i<N; i++) {
		cin >> A;
		num_to_cnt[A]++;
	}

	for (auto itr : num_to_cnt) {
		cnt.push_back(itr.second);
	}

	sort(cnt.begin(), cnt.end(), greater<int>());

	int ans = 0;

	for (int i=0; i<cnt.size(); i++) {
		if (i >= K) ans += cnt[i];
	}

	cout << ans << endl;

	return 0;
}