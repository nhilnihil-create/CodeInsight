#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

signed main(){
  int H, W, D; cin >> H >> W>> D;
  vector<P> data(H * W + 1);
  for(int i = 0; i < H; i++){
	  for(int j = 0; j < W; j++){
			int x; scanf("%d", &x);
			data[x] = P(i, j);
		}
  }
	vector<int> sum(H * W + 1, 0);
	for(int i = H * W - D; i >= 0; i--){
		int a = data[i].first, b = data[i].second, c = data[i + D].first, d = data[i + D].second;
		sum[i] = sum[i + D] + abs(a - c) + abs(b - d);
	}
	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		int l, r; scanf("%d%d", &l, &r);
		cout << sum[l] - sum[r] << '\n';
	}
}