#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	priority_queue<P, vector<P>, greater<P>> pq;
	for (auto c : mp) {
		pq.emplace(c.first, c.second);
	}
	while (m--) {
		int b, c;
		cin >> b >> c;
		int bt = b;
		while (b && c > pq.top().first) {
			P p = pq.top(); pq.pop();
			if (p.second >= b) {
				if (p.second != b) pq.emplace(p.first, p.second - b);
				b = 0;
				break;
			}
			b -= p.second;
		}
		pq.emplace(c, bt - b);
	}
	ll ans = 0;
	while (pq.size()) ans += (ll)pq.top().first * pq.top().second, pq.pop();
	cout << ans << endl;
	return 0;
}