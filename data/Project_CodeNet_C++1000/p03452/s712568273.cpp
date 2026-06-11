#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll v[100001];
vector<pair<ll, ll>> e[100001];
ll n, m;

void dfs(ll i, ll x) {
	v[i] = x;

	rep(p, 0, e[i].size()) {
		ll nextID = e[i][p].first;
		ll nextDistance = e[i][p].second;
		if (v[nextID]) {
			//visited
			if (v[i] + nextDistance != v[nextID]) {
				cout << "No";
				exit(0);
			}
		}
		else {
			//not visited
			dfs(nextID, v[i] + nextDistance);
		}
	}
}

int main() {
	cin >> n >> m;
	rep(i, 0, m) {
		ll l, r, d; cin >> l >> r >> d;
		e[l].push_back({ r,d });
		e[r].push_back({ l,-d });
	}

	repe(i, 1, n) {
		if (!v[i]) {
			dfs(i, 1e9 + 1);
		}
	}
	cout << "Yes" << endl;
	return 0;
}