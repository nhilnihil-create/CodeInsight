#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long int
#define F first
#define S second
#define pll pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vpii vector<pair<int,int> >
#define vvpii vector<vpii >
#define vpll vector<pair<ll,ll> >
#define vvpll vector<vpll >
#define pb push_back
#define MOD 1000000007
#define brk cout<<"\n"

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

struct compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if ((a.S - a.F) != (b.S - b.F)) return ((a.S - a.F) > (b.S - b.F));
		else return (a.F < b.F);
	}
};

const int mx = 16;
const ll INF = 1e18L + 5;
ll n;
vl dp, score;

void rec(ll i, vl & not_taken, ll score_so_far, ll mask, ll group) {
	if (i == not_taken.size()) {
		dp[mask] = max(dp[mask], score_so_far + score[group]);
		return;
	}
	rec(i + 1, not_taken, score_so_far, mask, group);
	rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]), group ^ (1 << not_taken[i]));

}



int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	FASTIO;
	cin >> n;
	vvl giv(n, vl(n));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) cin >> giv[i][j];
	}

	dp.resize(1 << n, -INF);
	score.resize(1 << n);
	dp[0] = 0;
	for (ll mask = 0; mask < (1 << n); mask++) {
		for (ll i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (ll j = i + 1; j < n; j++) {
					if (mask & (1 << j)) score[mask] += giv[i][j];
				}
			}
		}
	}
	for (ll mask = 0; mask < (1 << n); mask++) {
		vl not_taken;
		for (ll i = 0; i < n; i++) {
			if (!(mask & (1 << i))) {
				not_taken.pb(i);
			}
		}
		rec(0, not_taken, dp[mask], mask, 0);
	}

	cout << dp[(1 << n) - 1]; brk;


}