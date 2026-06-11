
// D - Cake 123

// 解説pdfの解法 #3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

using IDX = pair<int, pair<int, int>>;

ll A[1000], B[1000], C[1000];
map<IDX, bool> used;

int main() {
	ll X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	for (int i=0; i<X; i++) {
		cin >> A[i];
	}
	sort(A, A+X, greater<ll>());

	for (int i=0; i<Y; i++) {
		cin >> B[i];
	}
	sort(B, B+Y, greater<ll>());

	for (int i=0; i<Z; i++) {
		cin >> C[i];
	}
	sort(C, C+Z, greater<ll>());

	priority_queue<pair<ll, IDX>> pq;
	IDX idx = make_pair(0, make_pair(0, 0));
	pq.push(make_pair(A[0] + B[0] + C[0], idx));
	used[idx] = true;

	vector<ll> ans(K);
	for (int i=0; i<K; i++) {
		ans[i] = pq.top().first;
		IDX idx = pq.top().second;
		int a = idx.first;
		int b = idx.second.first;
		int c = idx.second.second;
		pq.pop();

		IDX next_idx;

		next_idx = make_pair(a+1, make_pair(b, c));
		if (used[next_idx] == false && a+1 < X) {
			pq.push(make_pair(A[a+1] + B[b] + C[c], next_idx));
			used[next_idx] = true;
		}

		next_idx = make_pair(a, make_pair(b+1, c));
		if (used[next_idx] == false && b+1 < Y) {
			pq.push(make_pair(A[a] + B[b+1] + C[c], next_idx));
			used[next_idx] = true;
		}

		next_idx = make_pair(a, make_pair(b, c+1));
		if (used[next_idx] == false && c+1 < Z) {
			pq.push(make_pair(A[a] + B[b] + C[c+1], next_idx));
			used[next_idx] = true;
		}
	}

	for (ll a : ans) {
		cout << a << endl;
	}

	return 0;
}