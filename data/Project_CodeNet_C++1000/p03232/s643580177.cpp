//Pantyhose(black) + glasses = infinity

#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define BP() cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define FILE_NAME "data"

const int MAX_N = 100002;
const int MOD = 1000000007;

int n, a[MAX_N];
int64_t ps[MAX_N], s[MAX_N];

void readInput() {
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
}

int64_t pw(int64_t n, int64_t k) {
	if (k==0)
		return 1;
	int64_t tmp = pw(n, k/2);
	if (k%2)
		return tmp * tmp % MOD * n % MOD;
	return tmp * tmp % MOD;
}

int64_t get(int l, int r) {
	return (ps[r] - ps[l-1] + MOD) % MOD;
}

void solve() {
	for (int i=1; i<=n; ++i)
		ps[i] = (ps[i-1] + a[i]) % MOD;
	int64_t fact = 1;
	for (int i=1; i<=n; ++i)
		fact = fact * i % MOD;
	int64_t res = 0;
	for (int i=1; i<=n; ++i) {
		s[i] = ((s[i-1] - get(n-i+2, n) + MOD + get(i, n))) % MOD;
		if (i==n) {
			res = (res + s[n] * fact) % MOD;
			break;
		}
		int64_t tmp1 = (get(1, i) + get(n-i+1, n)) % MOD;
		int64_t tmp2 = (s[i] - tmp1 + MOD) % MOD;
		res = (res + tmp1 * fact % MOD * pw(i+1, MOD-2)) % MOD;
		res = (res + tmp2 * fact % MOD * pw(1LL*(i+2)*(i+1)/2, MOD-2)) % MOD;
	}
	cout << res;
}

int main() {
	#ifdef GLASSES_GIRL
		freopen(FILE_NAME".inp", "r", stdin);
		freopen(FILE_NAME".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	readInput();
	solve();
}