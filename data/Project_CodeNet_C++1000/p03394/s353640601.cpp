#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1061109567
#define INFLL 4557430888798830399
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)
using namespace std;
int n;
vector<int> v;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	/*
	Firstly, a few elements are essential: 2, 3, 4 and 9. Then start putting multiples of 6 and
	we are good.
	*/
	if (n == 3) {
		cout << "2 5 63";
		return 0;
	}
	if (n == 5) {
		cout << "2 3 4 9 6";
		return 0;
	}
	v.pb(2), v.pb(3), v.pb(4), v.pb(9);
	n -= 4;
	int cur = 6;
	while (n > 1 && cur <= 30000) {
		v.pb(cur);
		n--;
		cur += 6;
	}
	cur = 8;
	while (n > 1 && cur <= 30000) {
		v.pb(cur), v.pb(cur + 2);
		n -= 2;
		cur += 6;
	}
	cur = 15;
	while (n > 1 && cur <= 30000) {
		v.pb(cur), v.pb(cur + 6);
		n -= 2;
		cur += 12;
	}
	if (n == 1) {
		v.erase(v.begin() + 4);
		v.pb(cur), v.pb(cur + 6);
	}
	fa (i, v) cout << i << " ";
	#ifdef BLU
	int sum = 0;
	fa (i, v) sum += i;
	fa (i, v) if (__gcd(i, sum - i) == 1) {
		cout << "NO";
		return 0;
	}
	#endif
	return 0;
}