#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	sort(h.begin(), h.end());
	int ans = INF;
	for (int i = 0; i+k-1 < n; i++)
	{
		ans = min(ans, h[i+k-1]-h[i]);
	}
	cout << ans << endl;
	return 0;
}