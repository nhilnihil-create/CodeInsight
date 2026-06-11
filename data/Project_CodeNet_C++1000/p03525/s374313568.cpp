#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
//	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vi d(n, 0);
	rep(i, n) cin >> d[i];
	sort(d.begin(), d.end());

	vi cnt(13, 0);
	rep(i, n) cnt[d[i]]++;

	if(cnt[0] > 0) {cout << 0 << endl; return 0; }
	rep1(i, 11) if(cnt[i] >= 3)  {cout << 0 << endl; return 0; }
	if(cnt[12] > 1) {cout << 0 << endl; return 0; }

	vector<bool> f(24, false);
	f[0] = true;
	rep1(i, 11) if(cnt[i] == 2) {f[i] = f[24-i] = true; }
	if(cnt[12] == 1) f[12] = true;

	bool right = true;
	rep1(i, 11) if(cnt[i] == 1) {
		if(right) f[i] = true;
		else f[24-i] = true;
		right = !right;
	}

	int pre = 0;
	int ans = 24;
	for(int i = 1; i < 24; i++) {
		if(f[i]) {
			ans = min(i - pre, ans);
			pre = i;
		}
	}
	ans = min(24 - pre, ans);
	cout << ans << endl;
}
