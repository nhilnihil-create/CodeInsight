
// C - Good Sequence

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	map<int, int> cnt;

	for (int i=0; i<N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	int ans = 0;
	for (auto itr : cnt) {
		int x = itr.first;
		int c = itr.second;
		if (c < x) ans += c;
		else ans += c - x;
	}

	cout << ans << endl;

	return 0;
}