
// C - Synthetic Kadomatsu

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, A, B, C;
int ans = INF;

void calc(vector<int>l, int mp) {
	int n = l.size();
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j == i) continue;
			for (int k=0; k<n; k++) {
				if (k == i || k == j) continue;

				ans = min(ans, mp + abs(l[i] - A) + abs(l[j] - B) + abs(l[k] - C));
			}
		}
	}
}

void solve(vector<int> l, int mp) {
	int n = l.size();

	/*
	// **** debug ****
	for (int i=0; i<n; i++) {
		cout << l[i] << " ";
	}
	cout << "mp=" << mp << endl;
	*/

	calc(l, mp);

	if (n <= 3) return;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			vector<int> nl;
			for (int k=0; k<i; k++) {
				nl.push_back(l[k]);
			}

			for (int k=i+1; k<n; k++) {
				if (k == j) nl.push_back(l[k] + l[i]);
				else nl.push_back(l[k]);
			}

			solve(nl, mp + 10);
		}
	}

}

int main() {
	cin >> N >> A >> B >> C;

	vector<int> l(N);
	for (int i=0; i<N; i++) {
		cin >> l[i];
	}

	solve(l, 0);

	cout << ans << endl;

	return 0;
}