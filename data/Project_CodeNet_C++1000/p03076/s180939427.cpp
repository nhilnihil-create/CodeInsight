#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main() {
	vector<int> time(5);
	cin >> time[0] >> time[1] >> time[2] >> time[3] >> time[4];

	vector<int> index = { 0, 1, 2, 3, 4 }; //順番の並び替え用の配列

	int bestTime = inf;

    do { //最初に一度実行
		int ans = 0;
		for (int i = 0; i < 5; ++i) {
			while (ans % 10 != 0) ans += 1; //10で割り切れるまで+1。10の倍数でしか次の注文ができないから
			ans += time[index[i]];
		}
		bestTime = min(bestTime, ans);
	} while (next_permutation(index.begin(), index.end())); //indexの組合わえを全探索してくれる

    cout << bestTime << endl;
	return 0;
}