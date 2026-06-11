#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "YES"
#define FALSE__ "NO"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

void init();
void solve();

signed main()
{
	init();
	solve();
}

vector<int> a;
static int n;

void init()
{
	cin >> n;
	CINV(a, n);
}

struct BIT {
	vector<int> v;
	int sz;
	BIT(int n) {
		sz = n+1;
		v.RS(sz, 0);
	}
	void add(int x) {
		for (int i = x; i <= sz; i += i & -i) v[i]++;
	}
	int get(int x) {
		int res = 0;
		for (int i = x; i > 0; i -= i & -i) res += v[i];
		return res;
	}
};

bool isok(int x)
{
	vector<int> b(n+1);
	b[0] = 0;
	rep(i, n) {
		if (a[i] >= x) b[i+1] = 1;
		else b[i+1] = -1;
		b[i+1] += b[i];
	}
	BIT bit(3 * n);
	ll res = 0;
	rep(i, n+1) {
		int t = bit.get(b[i] + n + 1);
		res += t;
		bit.add(b[i] + n + 1);
	}
	ll other = (ll) n * (n + 1) / 2 - res;
	return res >= other;
}

void solve()
{
	int ok = 29;
	int ng = 31;
	ng = 1111111111;
	ok = 1;
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (isok(mid)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}


