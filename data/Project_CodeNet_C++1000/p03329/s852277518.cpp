
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> w6;
	for (int i=1; pow(6, i) <= N; i++) {
		w6.push_back(pow(6, i));
	}
	sort(w6.begin(), w6.end(), greater<int>());

	vector<int> w9;
	for (int i=1; pow(9, i) <= N; i++) {
		w9.push_back(pow(9, i));
	}
	sort(w9.begin(), w9.end(), greater<int>());


	int ans = INF;
	for (int i=0; i<=N; i+=9) {
		int cnt = 0;

		// i円を9で引き出す
		int Y = i;
		for (int w : w9) {
			if (Y != 0) {
				cnt += Y / w;
				Y %= w;
			}
		}

		// 残りを6で引き出せるだけ引き出す
		Y = N - i;
		for (int w : w6) {
			if (Y - w >= 0) {
				cnt += Y / w;
				Y %= w;
			}
		}

		// 残りを1円で引き出す
		cnt += Y;

		// 最小なら更新
		ans = min(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}