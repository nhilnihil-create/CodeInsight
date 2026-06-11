#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int H, W, D;
	cin >> H >> W >> D;
	vector<int> px(H*W+1), py(H*W+1);
	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			int a;
			cin >> a;
			px[a] = i;
			py[a] = j;
		}
	}
	// 累積和
	vector<int> wa(H*W+1, 0);
	for(int i=1;i<=H*W;i++) {
		if(i+D <= H*W) wa[i+D] = wa[i] + (abs(px[i] - px[i+D]) + abs(py[i] - py[i+D]));
	}
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++) {
		int l, r;
		cin >> l >> r;
		cout << wa[r] - wa[l] << endl;
	}
}