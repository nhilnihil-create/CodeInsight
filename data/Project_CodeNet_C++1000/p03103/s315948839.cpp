#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	ll n, m, ans = 0,sum = 0,x,y;cin >> n >> m;
	vector<pair<ll, ll>> a(n);
	rep(i, n) {
		cin >> x >>  y;a[i] = make_pair(x, y);
	}
	sort(a.begin(), a.end());
	int i = 0;
	while (sum < m) {
		sum += a[i].second;
		ans += a[i].first * a[i].second;
		i++;
	}
	int u = sum - m;
	ans -= u * a[i - 1].first;
	cout << ans << endl;
}