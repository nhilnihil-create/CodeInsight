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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, to[26][MX];
string s;
char t[MX], d[MX];

int f (int i) {
	int j = 0;

	while (0 <= i && i < n && to[s[i] - 'A'][j] != -1) {
		j = to[s[i] - 'A'][j];
		if (d[j] == 'L') i--;
		else i++;
		j++;
	}

	if (i < 0) return -1;
	if (i >= n) return 1;
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(to, -1, sizeof(to));
	
	cin >> n >> q >> s;
	forn (i, q) {
		cin >> t[i] >> d[i];
		to[t[i] - 'A'][i] = i;
	}

	for (int i = q - 1; i >= 0; i--)
		forn (j, 26)
			if (to[j][i] == -1)
				to[j][i] = to[j][i + 1];

	int res = n;

	int i = 0, j = n - 1, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (f(m) == -1) i = m;
		else j = m;
	}
	if (f(i) == -1) res -= i + 1;

	i = 0, j = n - 1, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (f(m) == 1) j = m;
		else i = m;
	}
	if (f(j) == 1) res -= n - j;

	cout << res << endl;

	return 0;
}
