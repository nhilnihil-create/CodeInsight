#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 100000000000

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;

	vector<P> m;
	ll list[10] = { 2,5,5,4,5,6,3,7,6 };
	ll tmp;
	rep(i, M) {
		cin >> tmp;
		m.push_back(make_pair(tmp, list[tmp - 1]));
	}

	sort(ALL(m), greater<P>());

	vector<ll> dp(N+1,-INF);
	dp[0] = 0;
	rep2(i, 1, N+1) {
		rep(j, M) {
			if(i - m[j].second >= 0) {
				dp[i] = max(dp[i], dp[i - m[j].second] + 1);
			}
		}
	}

	ll num = N;
	deque<ll> ans;
	while (num > 0) {
		rep(j, M) {
			if ((num - m[j].second >= 0) && (dp[num] - 1 == dp[num - m[j].second])) {
				ans.push_back(m[j].first);
				num -= m[j].second;
				break;
			}
		}
	}

	rep(i,dp[N]) cout << ans[i];
	cout << "\n";

	return 0;
}