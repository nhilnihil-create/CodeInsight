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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int l, i;
vii adj[22];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> l;
	for (i = 1; (1 << i) <= l; i++) {
		adj[i-1].emplace_back(i, 0);
		adj[i-1].emplace_back(i, 1 << (i - 1));
	}
	i--;

	for (int j = 0, k = (1 << i); j < i; j++)
		if ((l - (1 << i)) & (1 << j)) {
			adj[j].emplace_back(i, k);
			k += (1 << j);
		}

	int m = 0;
	for (int j = 0; j <= i; j++)
		m += adj[j].size();

	cout << i + 1 << " " << m << endl;
	for (int j = 0; j <= i; j++)
		for (ii &e : adj[j])
			cout << j + 1 << " " << e.fi + 1 << " " << e.se << endl;

	return 0;
}
