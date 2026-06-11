#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
using namespace std;
using ll = long long;
const ll mxw = 20005;
const ll mxn = 3003;
ll N;

struct Box
{
	ll w, s, v;
};

bool cmp(const Box b1, const Box b2) {
	return (b1.w+b1.s)<(b2.w+b2.s);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<Box> Boxes;
	cin>>N;
	for(ll i=1; i<=N; i++) {
		ll w, s, v;
		cin>>w>>s>>v;
		Box b; b.w = w; b.s =s; b.v = v;
		Boxes.emplace_back(b);
	}

	sort(Boxes.begin(),Boxes.end(), cmp);

	vector<ll> dp (mxw, 0ll);
	for(auto x:Boxes) {
		vector<ll> new_dp(mxw, 0ll);
		for(ll j=0; j<mxw; j++) {
			if(j-x.w<0) new_dp[j] = dp[j];
			else if(j-x.w>x.s) new_dp[j] = dp[j];
			else new_dp[j] = max(dp[j-x.w]+x.v, dp[j]);
		}
		dp = new_dp;
	}

	ll ans = 0ll;
	for(ll i=0; i<mxw; i++) if(dp[i]>ans) ans = dp[i];
	cout << ans << '\n';

	return 0;
}