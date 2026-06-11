
// D - Practical Skill Test

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

using POS = pair<int, int>;

unordered_map<int, POS> n_to_pos;
int cum_pow[300 * 300 + 1];

int main() {
	int H, W, D;
	cin >> H >> W >> D;

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			int A;
			cin >> A;
			n_to_pos[A] = make_pair(i, j);
		}
	}

	// 事前計算
	for (int i=0; i<D; i++) {
		for (int l=i; l+D<=H*W; l+=D) {
			int r = l + D;

			POS l_pos = n_to_pos[l];
			POS r_pos = n_to_pos[r];

			int pow = abs(l_pos.first - r_pos.first) + abs(l_pos.second - r_pos.second);
			cum_pow[r] = cum_pow[l] + pow;
		}
	}

	int Q;
	cin >> Q;

	vector<int> ans;

	for (int i=0; i<Q; i++) {
		int L, R;
		cin >> L >> R;
		ans.push_back(cum_pow[R] - cum_pow[L]);
	}

	for (int a : ans) {
		cout << a << endl;
	}

	return 0;
}