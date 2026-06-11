#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, h;
	cin >> n >> h;
	priority_queue<P, V<P>, less<P>> p;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		p.push(P(a, 0));
		p.push(P(b, 1));
	}

	int ans = 0;
	while (h > 0) {
		int atk = p.top().first;
		if (p.top().second == 0) {
			ans += (h + atk - 1) / atk;
			h = 0;
		}
		else {
			ans++;
			h -= atk;
			p.pop();
		}
	}

	cout << ans << endl;

}