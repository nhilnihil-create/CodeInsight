#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e6 + 7;
const int Inf = 1 << 30;
const ll INF = 1LL << 60;
#define mst(x) memset(x, 0, sizeof(x))
ll n, p;
ll pr[maxx]; //p的所有因子
map <ll, bool> vis;
ll ans;

int main() {
	vis.clear();
	cin >> n >> p;
	if(n == 1) {
		cout << p << endl;
		return 0;
	}
	int tot = 0;
	for(int i = 1; i <= sqrt(p); i++) {
		if(p % i == 0) pr[++tot] = i;
	}
	int dd;
	double tmp = sqrt(p);
	if(tmp == (int)tmp) dd = tot - 1;
	else dd = tot;
	for(int i = 1; i <= dd; i++) pr[++tot] = p / pr[i];
	sort(pr + 1, pr + tot + 1);

	/* 如果除1以外的最小因子的n次幂都比p大, 那gcd必为1 */
	if(tot > 1) {
		ll f = pr[2]; //除1以外的最小因子
		ll m = 1;
		while(f * pr[2] <= p) {
			f *= pr[2];
			m++;
		}
		if(m < n) {
			puts("1");
			return 0;
		}
	}

	for(int i = 1; i <= tot; i++) vis[pr[i]] = 1;
	bool chk = 0;
	for(int i = tot; i >= 2; i--) {
		ll pp = pr[i];
		ll cnt = 1;
		bool flg = 0;
		while(pp * pr[i] <= p) {
			pp *= pr[i];
			cnt++;
			if(cnt == n) {
				flg = 1;
				break;
			}
		}
		if(flg && vis[pp]) {
			chk = 1;
			ans = pr[i];
			break;
		}
	}
	if(!chk) puts("1");
	else cout << ans << endl;
}