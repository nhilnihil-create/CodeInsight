#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int x[100010];
int main() {
	int n,m;
	cin >> n >> m;
	if (n >= m) {
		cout << 0 << endl;
		return 0;
	}
	rep(i,m) cin >> x[i];
	sort(x,x+m);
	
	vector<int> len(m-1);
	rep(i,m-1) {
		len[i] = x[i+1] - x[i];
	}
	sort(len.begin(), len.end(), greater<int>());
	ll ans = x[m-1] - x[0];
	rep(i,n-1) {
		ans -= len[i];
	}
	cout << ans << endl;

	return 0;
}