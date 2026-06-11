#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int H, W, D;
	cin >> H >> W >> D;
	vector<vector<int>> A(H, vector<int>(W));
	map<int,pair<int,int>> mp;
	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			cin >> A[i][j];
			mp[A[i][j]] = make_pair(i, j);
		}
	}
	// 累積和
	vector<int> wa(H*W+1, 0);
	for(int i=1;i<=H*W;i++) {
		if(i+D <= H*W) wa[i+D] = wa[i] + (abs(mp[i].first - mp[i+D].first) + abs(mp[i].second - mp[i+D].second));
	}
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++) {
		int l, r;
		cin >> l >> r;
		cout << wa[r] - wa[l] << endl;
	}
}