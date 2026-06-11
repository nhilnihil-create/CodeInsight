
// C - Exam and Wizard

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100000];
int B[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		cin >> B[i];
	}

	ll S = 0; // 不足分の合計
	int cntS = 0; // 不足するAの数
	vector<int> E; // 超過
	for (int i=0; i<N; i++) {
		if (A[i] < B[i]) {
			S += B[i] - A[i];
			cntS++;
		}

		if (A[i] > B[i]) {
			E.push_back(A[i] - B[i]);
		}
	}

	sort(E.begin(), E.end(), greater<int>());

	ll cntE = 0; // 補正に必要な、超過しているAの数
	for (int e : E) {
		if (S <= 0) break;
		S -= e;
		cntE++;
	}

	int ans;
	if (S > 0) ans = -1;
	else ans = cntS + cntE;

	cout << ans << endl;

	return 0;
}