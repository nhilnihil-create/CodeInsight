#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	int n;
	cin >> n;
	vector<pair<int,int>> red(n), blue(n);
	rep(i, n)  cin >> red[i].first >> red[i].second;
	rep(i, n)  cin >> blue[i].first >> blue[i].second;

	//処理
	sort(blue.begin(), blue.end());
	int ans = 0;
	rep(b, n) {
		int ymax = -1;
		int rmax = 0;
		rep(r, n) {
			if (red[r].first < blue[b].first && red[r].second < blue[b].second) {
					//x,yとも小さい
				if (ymax < red[r].second) {
					ymax = red[r].second;
					rmax = r;
				}
			}
		}
		if (ymax >= 0) {
			++ans;
			red[rmax].first = INT_MAX;
		}
	}


	//出力
	cout << ans << endl;

	return 0;
}
