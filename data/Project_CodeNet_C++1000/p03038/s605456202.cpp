#include<queue>
#include<iostream>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;


int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<ll, ll>> q;
	rep(i,n) {
		int a;
		cin >> a;
		q.push(make_pair(a, 1));
	}
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		q.push(make_pair(b, a));
	}
	int num = 0;
	ll ans = 0;
	while (true) {
		if (num >= n) break;
		auto p = q.top();
		q.pop();
		ans += p.first * min((ll)n - num, p.second);
		num += p.second;
	}
	cout << ans << endl;
	return 0;
}