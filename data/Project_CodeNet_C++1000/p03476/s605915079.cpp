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

struct Sieve {
	int n;
	vector<int> f, primes;
	Sieve(int n = 1) :n(n), f(n + 1) {
		f[0] = f[1] = -1;
		for (ll i = 2; i <= n; ++i) {
			if (f[i]) continue;
			primes.push_back(i);
			f[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				if (!f[j]) f[j] = i;
			}
		}
	}
	bool isPrime(int x) { return f[x] == x; }
	vector<int> factorList(int x) {
		vector<int> res;
		while (x != 1) {
			res.push_back(f[x]);
			x /= f[x];
		}
		return res;
	}
	vector<P> factor(int x) {
		vector<int> fl = factorList(x);
		if (fl.size() == 0) return {};
		vector<P> res(1, P(fl[0], 0));
		for (int p : fl) {
			if (res.back().first == p) {
				res.back().second++;
			}
			else {
				res.emplace_back(p, 1);
			}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 100000;
	Sieve si(n);
	vector<int> rec(100005);
	for (int i = 1; i <= n; i++) {
		if (si.isPrime(i) && si.isPrime((i + 1) / 2)) rec[i]++;
		rec[i + 1] += rec[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << rec[r] - rec[l - 1] << endl;
	}
	return 0;
}
