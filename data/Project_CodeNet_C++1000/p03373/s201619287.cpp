#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int z = max(x, y);
	int ans = 1e9;
	for(int i = 0; i <= 2 * z; i += 2){
		int x1 = i / 2, y1 = i / 2;
		int need_x = max(0, x - x1), need_y = max(0, y - y1);
		ans = min(ans, i * c + need_x * a + need_y * b);
	}
	cout << ans << endl;
}