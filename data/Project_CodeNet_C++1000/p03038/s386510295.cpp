#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N, M;
	cin >> N >> M;

	vector<int64_t> A(N);
	for (int64_t i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());

	vector<pair<int64_t, int64_t>> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int64_t vi = 0;
	for (int i = 0; i < N; i++) {
		if (vi >= M) break;
		if (A[i] < v[vi].first) {
			A[i] = v[vi].first;
			v[vi].second--;
		}
		if (!v[vi].second) vi++;
	}

	int64_t s = 0;
	for (int i = 0; i < N; i++) {
		s += A[i];
	}

	cout << s << endl;
}