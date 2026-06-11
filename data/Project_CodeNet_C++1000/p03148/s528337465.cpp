#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> vec(n);
	rep(i, n) {
		int t, d;
		cin >> t >> d;
		t--;
		vec[t].emplace_back(d);
	}
	vector<P> p;
	rep(i, n) {
		if (vec[i].size()) {
			sort(all(vec[i]));
			rep(j, vec[i].size()) {
				p.emplace_back(vec[i][j], j == vec[i].size() - 1);
			}
		}
	}
	sort(rall(p));
	priority_queue<int, vector<int>, greater<int>> pq;
	int ki = 0, ch = 0;
	ll tot = 0;
	ll ans = 0;
	rep(i, n) {
		int d = p[i].first, w = p[i].second;
		tot += d;
		ch++;
		ki += w;
		if (!w) pq.push(d);
		if (ch > k) {
			ch--;
			if (!pq.size()) break;
			tot -= pq.top();
			pq.pop();
		}
		if (ch == k) ans = max(ans, tot + (ll)ki * ki);
	}
	cout << ans << endl;
	return 0;
}
