#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	//各数字を1にかえる時の最短魔力を求めておく
	//warfloだったわ
	vector<vector<ll>>dp(10, vector<ll>(10, 100000000000));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)cin >> dp.at(i).at(j);
	}
	for (int i = 0; i < 10; i++)dp.at(i).at(i) = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++)dp.at(j).at(k) = min(dp.at(j).at(k), dp.at(j).at(i) + dp.at(i).at(k));
		}
	}
	//行列について足していきans出力
	ll ans = 0;
	for (int i = 0; i < h * w; i++) {
		ll x;
		cin >> x;
		if(x!=-1)ans += dp.at(x).at(1);
	}
	cout << ans << endl;
}