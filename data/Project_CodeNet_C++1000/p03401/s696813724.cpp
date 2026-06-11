
// C - Traveling Plan

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100002];

int main() {
	int N;
	cin >> N;

	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}
	A[N+1] = 0;

	int S = 0;
	for (int i=1; i<=N+1; i++) {
		S += abs(A[i] - A[i-1]);
	}

	vector<int> ans;
	for (int i=1; i<=N; i++) {
		int T = S;
		T -= abs(A[i] - A[i-1]);
		T -= abs(A[i+1] - A[i]);
		T += abs(A[i+1] - A[i-1]);
		ans.push_back(T);
	}

	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}