#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);

	int x = a[n-1], y = a[0], mx = min(y, x - y);

	for (int i = 1; i < n - 1; i++) {
		int d = min(a[i], x - a[i]);
		if (d > mx) {
			y = a[i];
			mx = d;
		}
	}

	cout << x << " " << y << endl;

	return 0;
}
