#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	ll suma = 0, sumb = 0;
	rep(i, n) suma += a[i];
	rep(i, n) sumb += b[i];
	ll res = sumb - suma;
	if (res < 0) {
		cout << "No" << endl;
		return 0;
	}
	ll tmp1 = 0, tmp2 = 0;
	rep(i, n) {
		if (a[i] > b[i]) {
			tmp1 += a[i] - b[i];
		}
		if (a[i] < b[i]) {
			tmp2 += (b[i] - a[i] + 1) / 2;
		}
	}
	if (tmp1 <= res && tmp2 <= res) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}