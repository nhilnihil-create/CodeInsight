#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
#define to second
#define cost first
typedef long long ll;
typedef long double ld;
using namespace std;

struct block {
	ll w, s, v;
	void read() {scanf("%lld%lld%lld", &w, &s, &v);}
};
bool cmp(block a, block b) {
	return a.s + a.w <= b.s + b.w;
}

int main()
{	
	ll i, j, k;
	ll n, mx = 20132;

	cin >> n;
	vector<block> v(n);
	for(int i = 0; i < n; i++) v[i].read();

	sort(v.begin(), v.end(), cmp);

	vector<ll> dp(mx+1, 0);

	for(block X : v) {
		for(int i = min(mx-X.w, X.s); i >= 0; i--) {
			dp[i+X.w] = max(dp[i+X.w], dp[i]+X.v);
		}
	}
	ll answer = 0;
	for(i = 0; i < dp.size(); i++) answer = max(answer, dp[i]);

	cout << answer << endl;

    return 0;
}