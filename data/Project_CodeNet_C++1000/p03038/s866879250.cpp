#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	int N, M; cin >> N >> M;
	vector<pair<int, int>> A;
	rep(i, N) {
		int a; cin >> a;
		A.push_back(make_pair(a, 1));
	}
	rep(j, M) {
		int b, c; cin >> b >> c;
		A.push_back(make_pair(c, b));
	}
	sort(A.begin(), A.end(), compare_by_b);
	long long ans = 0;
	int count = 0;
	rep(i, A.size()) {
		if (count + A[i].second >= N) {
			ans += (long long)A[i].first * (N - count);
			break;
		}
		else ans += (long long)A[i].first * A[i].second;
		count += A[i].second;
		//cout << ans << endl;
	}
	cout << ans;
}