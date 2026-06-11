#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	priority_queue<P, V<P>, greater<P>> pq;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		pq.push(P(a, b));
	}

	int k = 0;
	ll ans = 0;
	while (k < m) {
		P p = pq.top();pq.pop();
		int cost = p.first;
		int num = p.second;
		ans += (ll)cost * min(num, -k + m);
		k += min(num, -k + m);
	}

	cout << ans << endl;
}