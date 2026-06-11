
// A - Limited Insertion

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> b(N+1);

	for (int i=1; i<=N; i++) {
		cin >> b[i];
	}

	vector<int> ans;

	while(1) {
		bool removed = false;
		for (int i = b.size() - 1; i>=1; i--) {
			if (i == b[i]) {
				ans.push_back(b[i]);
				b.erase(b.begin() + i);
				removed = true;
				break;
			}
		}

		if (removed == false) break;
	}

	if (ans.size() == N) {
		reverse(ans.begin(), ans.end());
		for (int a : ans) {
			cout << a << endl;
		}
	} else {
		cout << -1 << endl;
	}

	return 0;
}