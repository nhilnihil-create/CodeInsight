#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
int cnt[MAX][4];
ll modExp(ll b, ll p) {
	ll res = 1;
	while(p > 0) {
		if(p & 1) res = (res * b) % MOD;
		b = (b * b) % MOD, p >>= 1;
	}
	return res;
}
void add(ll &a, ll b) {
	b %= MOD;
	a = (a + b) % MOD;
}
void mul(ll &a, ll b) {
	b %= MOD;
	a = (a * b) % MOD;
}
void sub(ll &a, ll b) {
	b %= MOD;
	a = (a - b) % MOD;
	a = (a + MOD) % MOD;
}
int get(int l, int r, int i) {
	return cnt[r][i] - cnt[l - 1][i];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	s = "X" + s;
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '?') cnt[i][3] ++;
		else cnt[i][s[i] - 'A'] ++;
		for(int j = 0; j < 4; j ++) cnt[i][j] += cnt[i - 1][j];
	}
 	for(int i = 1; i <= n; i ++) {
 		if(s[i] == 'A' || s[i] == 'C') continue;
		ll lft = get(1, i - 1, 0);
		ll rht = get(i + 1, n, 2);
		ll cur1 = (lft * rht) % MOD;
		mul(cur1, modExp(3, get(1, n, 3) - (s[i] == '?')));
		ll lq = get(1, i - 1, 3), rq = get(i + 1, n, 3);
		ll cur2 = 0;
		ll tmp = (lq * rht) % MOD;
		mul(tmp, modExp(3, lq + rq - 1));
		add(cur2, tmp);
		tmp = (lft * rq) % MOD;
		mul(tmp, modExp(3, lq + rq - 1));
		add(cur2, tmp);
		tmp = (lq * rq) % MOD;
		mul(tmp, modExp(3, lq + rq - 2));
		add(cur2, tmp);
		ll cur = cur1;
		add(cur, cur2);
		add(ans, cur);
 	}
 	cout << ans;
	
	return 0;
}