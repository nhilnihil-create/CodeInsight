#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
const lli INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1e9 + 7;
const lli MH1 = 1599614977, MH2 = 2034417103, MH3 = 1090250123, MH4 = 2024491871; 
const int N = 2e5 + 10;
lli tree[4*N];
lli dp[N];
pair<lli, lli> nums[N];
void update(int v, int l, int r, int pos, lli newVal) {
	if(l > r || l > pos || r < pos) return;
	if(l == r && l == pos) {tree[v] = newVal; return;}
	int v1 = 2 * v + 1;
	int v2 = 2 * v + 2;
	int mid = (l + r) / 2;
	update(v1, l, mid, pos, newVal);
	update(v2, mid + 1, r, pos, newVal);
	tree[v] = max(tree[v1], tree[v2]);
}
lli query(int v, int l, int r, int L, int R) {
	if(l > r || l > R || r < L) return -INF64;
	if(L <= l && r <= R) return tree[v];
	int v1 = 2 * v + 1;
	int v2 = 2 * v + 2;
	int mid = (l + r) / 2;
	lli q1 = query(v1, l, mid, L, R);
	lli q2 = query(v2, mid + 1, r, L, R);
	return max(q1, q2); 
}
lli bpow(lli baseee, lli exponenttt) {
	if(exponenttt < 0) return 0;
	lli res = 1;
	baseee %= MOD;
	while (exponenttt > 0) {
		if ((exponenttt & 1) == 1) res = (res*baseee) % MOD;
		baseee = (baseee*baseee) % MOD;
		exponenttt >>= 1;
	}
	return res;
}
lli multInverse(lli a) {//if_mod_is_prime
	return bpow(a, MOD - 2);
}
lli divm(lli a, lli b) {//if_mod_is_prime
	return (a * multInverse(b)) % MOD;
}
lli multm(lli a, lli b) {
	return (a * b) % MOD;
}
lli subm(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli addm(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<lli, lli>> qq;
	for(int i = 1; i <= n; i++)
		cin >> nums[i].first;
	for(int i = 1; i <= n; i++)
		cin >> nums[i].second;
	for(int i = 1; i <= n; i++) 
		qq.push_back({nums[i].first, i});
	sort(qq.begin(), qq.end());
	
	for(auto jj : qq) {
		lli i = jj.second;
		dp[i] = query(0, 1, n, 1, i) + nums[i].second;
		update(0, 1, n, i, dp[i]);
	}
	cout << *max_element(dp + 1, dp + n + 1) << "\n";
	return 0;
}