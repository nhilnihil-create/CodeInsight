#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<18, rt = 1<<10;
int f[maxn];
void add(int x) {
	for(x += maxn/2; x < maxn; x += x&-x) f[x]++;
}
int get(int x) {
	int res = 0;
	for(x += maxn/2; x; x -= x&-x) res += f[x];
	return res;
}
int n, a[maxn];
ll all = 0;
void read() {
	cin >> n;
	all = n * 1ll * (n+1) / 2;
	for(int i = 1; i <= n; i++) cin >> a[i];
}
bool check(int x) {
	memset(f, 0, sizeof f);
	ll cnt = 0;
	add(0);
	for(int p = 0, i = 1; i <= n; i++) {
		int t = a[i] < x ? -1 : 1;
		//cout << t << " ";
		p += t;
		add(p);
		cnt += i+1-get(p);
	}
	//cout << '\n';
	//cout << x << " " << cnt << '\n';
	//cout << "Verdict: " << (cnt >= all-cnt) << '\n';
	return cnt > all-cnt;
}
void solve() {
	int ans = 0;
	for(int i = 1<<30; i >>= 1;) {
		if(!check(ans + i)) ans += i;
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	read();
	solve();
}
