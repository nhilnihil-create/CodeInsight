#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 100005;
int n, a[MX], b[MX];
vi c;

bool esPos (int m) {
	ll res = 0;

	for (int i = 1; i <= n; i++)
		b[i] = a[i] <= c[m] ? 1 : -1;

	ordered_set st;
	st.insert(ii(0, 0));

	for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
		res += st.order_of_key(ii(b[i], -1));
		st.insert(ii(b[i], i));
	}

	return res >= (1ll * n * (n + 1) / 2) / 2 + 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c.pb(a[i]);
	}

	sort(all(c));

	int i = 0, j = (int)c.size() - 1, rep = 20;

	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << c[j] << endl;

	return 0;
}
