#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int H, W, N, diff = 0;
	static pair<int, int> point[200000];
	cin >> H >> W >> N;
	for (int i = 0;i < N;++ i) cin >> point[i].first >> point[i].second;
	sort(point, point+N); // X昇順、同値ならY昇順
	for (int i = 0;i < N;++ i) {
		if (point[i].first - point[i].second - diff > 0) H = min(H, point[i].first - 1); // この障害物を使って邪魔する
		else if (point[i].first - point[i].second - diff == 0) ++ diff; // 青木君が移動できないので、上を抜けるしかない
	}
	cout << H;
	return 0;
}