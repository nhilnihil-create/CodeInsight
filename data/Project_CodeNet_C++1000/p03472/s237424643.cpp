#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, h;
	cin >> n >> h;
	priority_queue<pii> q;
	rep(i,n) {
		int a, b;
		cin >> a >> b;
		q.push(make_pair(a, 1));
		q.push(make_pair(b, 0));
	}
	ll cur = h;
	ll cnt = 0;
	while (true) {
		auto p = q.top();
		q.pop();
		if (p.second) {
			cout << (cur + (p.first - 1)) / p.first + cnt << endl;
			return;
		}
		cur -= p.first;
		cnt++;
		if (cur <= 0) {
			cout << cnt << endl;
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}