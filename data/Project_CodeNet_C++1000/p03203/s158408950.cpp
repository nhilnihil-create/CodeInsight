#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
vector<int> ys[maxn];
int main(){
	int h, w, n;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		ys[x].push_back(y);
	}
	int ans = h, y = 1;
	for(int i = 2; i <= h; i++){
		sort(ys[i].begin(), ys[i].end());
		bool has = false;
		for(int v : ys[i]){
			if(v <= y) ans = min(ans, i - 1);
			if(v == y + 1) has = true;
		}
		if(!has) y++;
	}
	cout << ans << endl;
	return 0;
}
