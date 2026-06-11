
// C - GeT AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int cnt_ac[100001];

int main() {
	int N, Q;
	string S;
	cin >> N >> Q >> S;

	for (int i=1; i<N; i++) {
		if (S[i-1] == 'A' && S[i] == 'C') cnt_ac[i] = cnt_ac[i-1] + 1;
		else cnt_ac[i] = cnt_ac[i-1];
	}

	vector<int> ans;
	for (int i=0; i<Q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		ans.push_back(cnt_ac[r] - cnt_ac[max(0, l)]);
	}

	for (int a : ans) {
		cout << a << endl;
	}

	return 0;
}