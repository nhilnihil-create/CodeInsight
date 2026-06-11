#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 6;//, mod = 1e9 + 7;
int n, m, k, ans = 1<<30;
set<pi> blocked;
set<int> fy[maxn];
bool can(pi t) {
	if(t.first>n) return false;
	if(t.second>m) return false;
	return 1^blocked.count(t);
}
int get(int x, int y) {
	auto it = fy[y].lower_bound(x);
	if(it==fy[y].end()) return 1<<30;
	return *it - 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int x, y, i = 0; i < k; i++) {
		cin >> x >> y;
		blocked.insert(pi(x, y));
		fy[y].insert(x);
	}
	int cx = 1, cy = 1, play = 1;
        ans = get(1, 1);
	while(true) {
		play = 0;
		if(can(pi(cx+1, cy))) {
			play = 1;
			cx++;
		}
		if(!play) break;
		if(can(pi(cx, cy+1))) {
			cy++;
			ans = min(ans, get(cx, cy));
		}
	}
	cout << min(ans, cx);
}

