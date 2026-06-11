#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	int N, Q;
	cin >> N >> Q >> S;

	vector<int> v(S.size());
	for (int i = 1; i < S.size(); i++) {
		if (S[i] == 'C') {
			if (S[i - 1] == 'A') v[i] = v[i - 1] + 1;
			else v[i] = v[i - 1];
		}
		else {
			v[i] = v[i - 1];
		}
	}

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int ans = v[r] - v[l];
		cout << ans << endl;
	}
}