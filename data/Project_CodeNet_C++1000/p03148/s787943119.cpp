#include"bits/stdc++.h"
#include<cassert>
#define fr first
#define sc second
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 998244353;
const long long inf = 1ll << 62;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int t[100006], d[100006];
P p[100006];
int ut[100006];
signed main() {
	int n, k; cin >> n >> k;
	rep(i, n)cin >> t[i] >> d[i];
	rep(i, n)p[i] = P(d[i], t[i]);
	sort(p, p + n);
	reverse(p, p + n);
	int ans = 0, now = 0;
	set<int>S;
	priority_queue<P>Q;
	priority_queue<P, vector<P>, greater<P>>Q1;
	rep(i, k) {
		now += p[i].first;
		S.insert(p[i].second);
		ut[p[i].second]++;
		if (ut[p[i].second] > 1)Q1.push(p[i]);
	}
	int Z = S.size();
	ans=now+ Z*Z;
	for (int i = k; i < n; i++)Q.push(p[i]);
	while (Q.size()) {
		P x = Q.top();
		Q.pop();
		if (ut[x.second])continue;
		if (Q1.size()) {
			P y = Q1.top(); Q1.pop();
			Z++;
			ut[x.second]++;
			now -= y.first;
			now += x.first;
		}
		ans = max(ans, now + Z*Z);
	}
	cout << ans << endl;
}