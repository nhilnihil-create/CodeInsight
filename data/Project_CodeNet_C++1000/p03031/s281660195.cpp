#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N, M; cin >> N >> M;
 
	vector<vector<int>> v(M);
 
	for (int i = 0; i < M; ++i) {
		int k; cin >> k;
		v[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> v[i][j];
			--v[i][j];
		}
	}
 
	vector<int> p(M);
	for (int i = 0; i < M; ++i) cin >> p[i];
 
	int ans = 0;
	for (int bit = 0; bit < (1 << N); bit++) {  // bit<(1<<n)でbitにはN桁以下の2進数が入る
                                                // bitはスイッチの入れ方
		bool flg = true;
		for (int j = 0; j < M; ++j) {
			int c = 0;
			for (int id : v[j]) {
				if ((bit >> id) & 1) { // onになっているスイッチのカウント
					c++;
				}
			}
			c %= 2;
			if (c != p[j]) { // 点灯できないとき ansにはカウントしない
				flg = false;
			}
		}
		if (flg) {  // 全部付けられたときカウントする
		    ans++;
		}
	}
 
	cout << ans << endl;
 
	return 0;
}