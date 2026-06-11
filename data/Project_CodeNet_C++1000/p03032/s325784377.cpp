#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n, k;;
	cin >> n >> k;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	int ans = 0;
	rep(i, n + 1) rep(j, n - i + 1) {
		int rest = k - i - j;
		if (rest < 0) continue;
		deque<int> q(v.begin(), v.end());
		priority_queue<int> poppen;
		int tans = 0;
		rep(k, i) {
			int t = q.front(); q.pop_front();
			tans += t;
			poppen.push(-t);
		}
		rep(k, j) {
			int t = q.back(); q.pop_back();
			tans += t;
			poppen.push(-t);
		}
		rep(k, rest) {
			if (poppen.empty()) break;
			int t = -poppen.top();
			if (t < 0) {
				tans -= t;
				poppen.pop();
			} else break;
		}
		chmax(ans, tans);
	}
	cout << ans << endl;
}