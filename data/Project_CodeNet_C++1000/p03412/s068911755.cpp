#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<18, rt = 1<<10;
int ra[maxn], a[maxn], rb[maxn], b[maxn], n;
int count(int x) {
	int res = 0;
	for(int j = n, i = 1; i <= n; i++) {
		while(j && b[j] + a[i] >= x) j--;
		res ^= n-j;
	}
	return res&1;
}
int solve(int i) {
	int msk = (1<<(i+1))-1;
	for(int i = 1; i <= n; i++) a[i] = ra[i]&msk;
	for(int i = 1; i <= n; i++) b[i] = rb[i]&msk;
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	return count(1<<i)^count(1<<(i+1))^count(1<<i | 1<<(i+1));
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> ra[i];
	for(int i = 1; i <= n; i++) cin >> rb[i];
	int ans = 0;
	for(int i = 0; i < 29; i++) {
		ans += solve(i)<<i;
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
