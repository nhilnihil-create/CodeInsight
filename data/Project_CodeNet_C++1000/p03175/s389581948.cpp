#include <bits/stdc++.h>

using namespace std;
// 0 white, 1 black

#define mkp make_pair
#define pb push_back

typedef long long ll;
const ll modl = 1e9 + 7;

vector<int> gr[100005];
ll dp[100005][2];

ll getForComponent(ll node, int par , int color) {

	if (dp[node][color] != -1) {
		return dp[node][color];
	}

	ll cur = 1ll, one, two;

	for (int child : gr[node]) {

		if (child != par) {
			if (color == 1) {
				cur *= getForComponent(child, node, 0);
			} else {
				one = getForComponent(child, node, 0);
				two = getForComponent(child, node, 1);
				cur   *= (one + two);
			}
		}
		cur = (cur % modl);
	}

	return dp[node][color] = (cur % modl);

}

int main() {

	memset(dp, -1, sizeof dp);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) gr[i].clear();
	for (int i = 0; i < n - 1; i++) {
		int s, l;
		cin >> s >> l;
		gr[s].pb(l);
		gr[l].pb(s);
	}

	ll ans = 1;
	ll one = getForComponent(1, -1, 0);
	ll second = getForComponent(1, -1, 1);
	ans = (( ans * ( one + second )) % modl ) ;

	cout << ans << endl;
	return 0;
}