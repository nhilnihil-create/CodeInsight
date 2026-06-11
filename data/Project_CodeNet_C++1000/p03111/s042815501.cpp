
// C - Synthetic Kadomatsu

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, A, B, C;
int ans = INF;
vector<int> l;
vector<int> A_l, B_l, C_l;

int calc_mp(vector<int> X_l, int X) {
	int total_l = 0;
	for (int x : X_l) {
		total_l += x;
	}

	return abs(X - total_l);
}

void calc() {
	if (A_l.size() == 0 || B_l.size() == 0 || C_l.size() == 0) return;

	int total_mp = 0;

	total_mp += calc_mp(A_l, A) + 10 * (A_l.size() - 1);
	total_mp += calc_mp(B_l, B) + 10 * (B_l.size() - 1);
	total_mp += calc_mp(C_l, C) + 10 * (C_l.size() - 1);

	ans = min(ans, total_mp);
}

// 竹k(0-index)をA〜Cのどれかに割り当てるか、どれにも割り当てない
void synth(int k) {
	if (k == N) {
		calc();
		return;
	}

	A_l.push_back(l[k]);
	synth(k+1);
	A_l.pop_back();

	B_l.push_back(l[k]);
	synth(k+1);
	B_l.pop_back();

	C_l.push_back(l[k]);
	synth(k+1);
	C_l.pop_back();

	synth(k+1); // 割り当てない
}

int main() {
	cin >> N >> A >> B >> C;

	l = vector<int>(N);
	for (int i=0; i<N; i++) {
		cin >> l[i];
	}

	synth(0);

	cout << ans << endl;

	return 0;
}