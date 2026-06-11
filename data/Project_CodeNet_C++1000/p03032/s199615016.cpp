#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;


int main() {

	int n, k;
	cin >> n >> k;
	vi v(n);
	rep(i, n)cin >> v[i];

	vi lsum(n + 1, 0), rsum(n + 1, 0);
	rep1(i, n) {
		lsum[i] = lsum[i - 1] + v[i - 1];
		rsum[i] = rsum[i - 1] + v[n - i];
	}

	int ans = -INF;
	rep(i, n+1)rep(j, n+1) {
		if (i + j > min(n, k))continue;
		priority_queue<int,vi,greater<int>> pq;
		rep(l, i)if (v[l] < 0)pq.push(v[l]);
		rep(l, j)if (v[n - 1 - l] < 0)pq.push(v[n - 1 - l]);
		int val = lsum[i] + rsum[j];
		rep(l, k - i - j)if (pq.size() > 0) { val -= pq.top();pq.pop(); }
		ans = max(ans, val);
	}

	cout << ans << endl;
}