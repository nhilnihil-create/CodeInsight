#include <bits/stdc++.h>

#define int long long

#define For(i,a,b) for (int i = a; i <= (b); ++i)
#define For2(i,a,b) for (int i = a; i >= (b); --i)

#define test int _t; cin >> _t; while (_t--)

#define pii pair<int, int>
#define mpii map<int, int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) (int)a.size()

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF 2147483647
#define EPS 1e-9

//#define FILEOPEN

using namespace std;

const int MAXN = (1 << 18) + 5;

int a[MAXN], ans[MAXN];
multiset<int, greater<int> > s[MAXN];

multiset<int, greater<int> > two_last(multiset<int, greater<int> > f) {
	int p = 0;
	if (sz(f) <= 2) return f;
	multiset<int, greater<int> > res;
	for (int i: f) {
		if (++p == 3) break;
		res.insert(i);
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifdef FILEOPEN
		freopen("input.in", "r", stdin);
		freopen("input.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	For(i,0,(1 << n) - 1) cin >> a[i];
	// cerr << 1;
	For(i,0,(1 << n) - 1) {
		// cerr << a[i] << endl;
		s[i].insert(a[i]);
	}
	For(bit,0,n - 1) {
		For(x,0,(1 << n) - 1) {
			if (!(x & (1 << (bit)))) {
				int f = (x | (1 << bit));
				for (auto i: s[x]) s[f].insert(i);
				s[f] = two_last(s[f]); 
			}
		}
	}
	ans[0] = -INF;
	For(k,1,(1 << n) - 1) {
		int sum = 0;
		for (int i: s[k]) sum += i;
		ans[k] = max(ans[k - 1], sum);
		cout << ans[k] << endl;
	}
}