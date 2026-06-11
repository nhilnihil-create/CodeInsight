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
const ll linf = (1LL << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	int r = min(n, k);
	int ans = 0;
	rep(a, r + 1)rep(b, r + 1) {
		if (a + b > r) continue;
		int tmp = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		rep(i, a) {
			tmp += v[i];
			if (v[i] < 0) pq.push(v[i]);
		}
		rrep(i, b + 1) {
			tmp += v[n - i];
			if (v[n - i] < 0) pq.push(v[n - i]);
		}
		rep(i, k - (a + b)) {
			if (pq.empty()) break;
			tmp -= pq.top();
			pq.pop();
		}
		maxs(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}