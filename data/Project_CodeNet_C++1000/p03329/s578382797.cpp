#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {
	
	int n;
	cin >> n;
	vi a(n + 1, INF);
	a[0] = 0;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		
		int v = q.front();
		q.pop();

		if (v + 1 <= n)if (a[v + 1] == INF) {
			a[v + 1] = a[v] + 1;
			q.push(v + 1);
		}

		int mon = 6;
		while (v + mon <= n) {
			if (a[v + mon] == INF) {
				a[v + mon] = a[v] + 1;
				q.push(v + mon);
			}
			mon *= 6;
		}
		mon = 9;
		while (v + mon <= n) {
			if (a[v + mon] == INF) {
				a[v + mon] = a[v] + 1;
				q.push(v + mon);
			}
			mon *= 9;
		}
	}
	
	cout << a[n] << endl;

}