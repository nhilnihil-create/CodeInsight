#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, k;
	cin >> n >> k;
	
	V<ll> sum(n + 1, 0);
	rep(i, n) { int a;cin >> a;sum[i + 1] = sum[i] + a; }

	queue<ll> que;
	rep(i, n + 1)rep(j, n + 1) {if (i <= j)continue;que.push(sum[i] - sum[j]);}

	ll ans = 0;

	rep(i, 64) {

		int q = que.size();
		queue <ll> match;
		rep(j,q) {
			ll a = que.front();que.pop();que.push(a);
			if (a >> (63 - i) & 1)match.push(a);
		}
		if (match.size() >= k) {
			ans += 1LL << (63 - i);
			que = match;
		}

	}

	cout << ans << endl;

}