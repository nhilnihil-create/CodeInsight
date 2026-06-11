#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define vel vector<long long>
#define vvel vector<vel>
#define int long long
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 998244353;
vel kai(4001, 1);
vel ink(4001, 1);
vel uni(vel &list) {
	if (list.size() == 0) { return list; }
	sort(list.begin(), list.end());
	vel ql(1, list[0]);
	rep(i, list.size() - 1) {
		if (list[i] != list[i + 1]) { ql.push_back(list[i + 1]); }
	}
	return ql;
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, 4000) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, 4001) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
signed main() {
	int n; cin >> n;
	vel a(1 << n);
	rep(i, 1 << n) { cin >> a[i]; }
	vel ans(1 << n, 0);
	V<V<pin>> mx((1<<n), V<pin>(2)); mx[0][0] = mkp(a[0], 0); mx[0][1] = mkp(0, 0);
	for (int i = 1; i < (1 << n); i++) {
		ans[i] = ans[i - 1];
		set<pin> li;
		rep(j, n) {
			if ((i >> j) % 2 == 1) {
				int mi = i ^ (1 << j);
				li.insert(mx[mi][0]);
				li.insert(mx[mi][1]);
			}
		}
		li.insert(mkp(a[i],i));
		auto itr = li.end();itr--;
		mx[i][0] = *itr; itr--; mx[i][1] = *itr;
		int qans = mx[i][0].first + mx[i][1].first;
		ans[i] = max(ans[i], qans);
		cout << ans[i] << endl;
	}
	return 0;
}
