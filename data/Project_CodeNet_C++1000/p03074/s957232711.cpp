
// D - Handstand

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, K;
	string S;

	cin >> N >> K;
	cin >> S;

	vector<int> T;
	if (S[0] == '0') {
		T.push_back(0);
	}

	int cnt = 1;
	for (int i=1; i<N; i++) {
		if (S[i-1] == S[i]) {
			cnt++;
		} else {
			T.push_back(cnt);
			cnt = 1;
		}
	}
	T.push_back(cnt);

	if (S[N-1] == '0') {
		T.push_back(0);
	}

	vector<int> U(T.size() + 1);
	for (int i=0; i < T.size(); i++) {
		U[i+1] = U[i] + T[i];
	}

	int ans = 0;
	for (int l=0; l<U.size(); l+=2) {
		int r = min(l+(2*K)+1, (int)U.size()-1);
		ans = max(ans, U[r] - U[l]);
	}

	cout << ans << endl;

	return 0;
}