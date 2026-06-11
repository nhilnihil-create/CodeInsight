#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct spell {
	char t, d;
	spell() : t(' '), d(' ') {}
	spell(char t, char d) : t(t), d(d) {}
};

int N, Q;
string s;
vector<spell> spells;

// マスstのゴーレムが最終的に至る座標
int final_idx(int st) {
	if (st < 0) return -1;
	if (st > N) return N;
	for (int i = 0; i < Q; ++i) {
		if (s[st] == spells[i].t) { // 移動の対象
			if (spells[i].d == 'L') --st;
			else ++st;
		}
		if (st < 0) return -1;
		if (st >= N) return N;
	}
	return st;
}

int main() {
	cin >> N >> Q;
	spells.resize(Q);
	cin >> s;
	for (int i = 0; i < Q; ++i) {
		char t, d; cin >> t >> d;
		spells[i] = spell(t, d);
	}
	// 左端から落下しない最小のindexを求める
	int fall = -1, safe_left = N;
	while (safe_left - fall > 1) {
		int mid = (fall + safe_left) / 2;
		int tmp = final_idx(mid);
		if (tmp == -1) fall = mid;
		else safe_left = mid;
	}
	// 右端から落下しない最大のindexを求める
	fall = N; int safe_right = -1;
	while (fall - safe_right > 1) {
		int mid = (fall + safe_right) / 2;
		int tmp = final_idx(mid);
		if (tmp == N) fall = mid;
		else safe_right = mid;
	}
	// cout << safe_right << " " << safe_left << endl;
	cout << (safe_right - safe_left + 1) << endl;
	return 0;
}