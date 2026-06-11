#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX], x;
__int128 res = __int128(1) << 126;

ll query (int i, int j) { return a[j] - a[i-1]; }

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	for (int i = 1; i <= n; i++) {
		__int128 acu = i * x + 5 * query(n-i+1, n);

		for (int j = 2, k = n - i; k > 0; j++, k -= i)
			acu += (2 * j + 1) * query(max(1, k-i+1), k);

		res = min(res, acu); 
	}

	cout << ll(res + __int128(n * x)) << endl;

	return 0;
}