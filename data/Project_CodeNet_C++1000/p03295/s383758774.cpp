#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
P b[100010];
int main() {
	int n, m;
	cin >> n >> m;
	int x,y;
	rep(i,m) {
		cin >> x >> y;
		b[i] = {y,x};
	}

	sort(b,b+m);
	int r = b[0].first; 
	int ans = 0;
	rep(i,m) {
		while (b[i].second < r && i < m) i++;
		if (i == m-1) i--;
		ans++;
		r = b[i].first;
	}
	cout << ans << endl;
	return 0;
}