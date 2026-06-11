#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
int p = 998244353;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
int kai_size = 400001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
int RE() {
	vel v(3, 2);
	return v.at(4);
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
	rep(i, kai_size) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, kai_size) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
int per(int n, int r) {
	int ans = kai[n] * ink[n - r];
	ans %= p;
	return ans;
}
signed main() {
	int n; cin >> n;
	vel r(n);
	vel l(n);
	V<pin> list_l(n);
	V<pin> list_r(n);
	rep(i, n) {
		cin >> l[i] >> r[i];
		list_l[i] = mkp(l[i], i);
		list_r[i] = mkp(r[i], i);
	}
	sor(list_l);
	auto itrl = list_l.begin();
	auto itrr = list_r.begin();
	sor(list_r);
	reverse(list_l.begin(), list_l.end());
	veb is_use(n,false);
	int ret = 0;
	bool is_nex_r = true;
	int now_pot = 0;
	int ans0 = 0;
	rep(i, n) {
		if (is_nex_r) {
			while (is_use[(*itrr).second]) {
				itrr++;
			}
			is_use[(*itrr).second] = true;
			int num = (*itrr).second;
			if (now_pot < l[num]) { ans0 += l[num] - now_pot; now_pot = l[num]; }
			else if (r[num] < now_pot) { ans0 += now_pot - r[num]; now_pot = r[num]; }
			is_nex_r = false;
		}
		else{
			while (is_use[(*itrl).second]) {
				itrl++;
			}
			is_use[(*itrl).second] = true;
			int num = (*itrl).second;
			if (now_pot < l[num]) { ans0 += l[num] - now_pot; now_pot = l[num]; }
			else if (r[num] < now_pot) { ans0 += now_pot - r[num]; now_pot = r[num]; }
			is_nex_r = true;
		}
	}
	ans0 += abs(now_pot);
	ret = ans0;
	itrl = list_l.begin();
	itrr = list_r.begin();
	is_use = veb(n, false);
	is_nex_r = false;
	now_pot = 0;
	ans0 = 0;
	rep(i, n) {
		if (is_nex_r) {
			while (is_use[(*itrr).second]) {
				itrr++;
			}
			is_use[(*itrr).second] = true;
			int num = (*itrr).second;
			if (now_pot < l[num]) { ans0 += l[num] - now_pot; now_pot = l[num]; }
			else if (r[num] < now_pot) { ans0 += now_pot - r[num]; now_pot = r[num]; }
			is_nex_r = false;
		}
		else {
			while (is_use[(*itrl).second]) {
				itrl++;
			}
			is_use[(*itrl).second] = true;
			int num = (*itrl).second;
			if (now_pot < l[num]) { ans0 += l[num] - now_pot; now_pot = l[num]; }
			else if (r[num] < now_pot) { ans0 += now_pot - r[num]; now_pot = r[num]; }
			is_nex_r = true;
		}
	}
	ans0 += abs(now_pot);
	mmax(ret, ans0);
	cout << ret << Endl;
	return 0;
}
