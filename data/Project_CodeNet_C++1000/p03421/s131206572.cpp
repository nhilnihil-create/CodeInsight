#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pair<int, int>>
#define mems(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define forn(i, s, e) for(int i = s; i < (e); ++i)
#define FASTIO                                                                                     \
	ios_base::sync_with_stdio(false);                                                              \
	cin.tie(NULL);
#define FILEIO                                                                                     \
	freopen("./input.txt", "r", stdin);                                                            \
	freopen("./output.txt", "w", stdout);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                                                  \
	for(auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second;  \
		debug("%s : %lld ms\n ",                                                                   \
			  d,                                                                                   \
			  chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() -   \
														  blockTime.first)                         \
				  .count()),                                                                       \
			 blockTime.second = false)
const int M = 1e9 + 7;

template <class T>
T ABS(const T& x) {
	return x > 0 ? x : -x;
}
ll gcd(ll n1, ll n2) { return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2); }
ll lcm(ll n1, ll n2) { return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2); }
ll ceil2(ll a, ll b) { return (a + b - 1) / b; }

int main() {
	FASTIO
#ifdef LOCAL
	FILEIO
#endif
	ll n, a, b;
	cin >> n >> a >> b;

	if(n < a + b - 1 || n > a * b) {
		puts("-1");
		return 0;
	}

	int ans[n];
	int cnt = n / a, val = 1;
	int lenb = ceil2(n, a);
	for(int i = 0; i < a; ++i) {

		int idx = i + cnt * a;
		if(idx >= n) {
			--cnt;
			idx = idx - a;
		}
		while(idx >= 0) {
			// cout << idx << endl;
			ans[idx] = val++;
			idx -= a;
		}
	}

	if(lenb < b) {
		// cout << lenb << endl;
		int need = b - lenb + 1;
		int idx = n - 1, currb = idx / a;
		vi tmp;
		while(need > 0) {
			if((idx / a) != currb) {
				++need;
				currb = idx / a;
			}
			// cerr << idx << endl;
			tmp.push_back(ans[idx--]);
			--need;
		}
		sort(tmp.rbegin(), tmp.rend());
		int j = 0;
		// cout << idx << endl;
		for(int i = idx + 1; i < n; ++i, ++j) { ans[i] = tmp[j]; }
	}

	for(int i = 0; i < n; ++i) { cout << ans[i] << " "; }

	return 0;
}