#include <bits/stdc++.h>
using namespace std;

#define sswap(x, y) { x+=y; y=x-y; x-=y; }
#define LSOne(S) ((S) & (-S))

#define EPS 1e-6
#define MOD 1000000007

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	int n, q;
	string s;
	cin >> n >> q >> s;
	int v[n+12];
	v[0] = 0;
	for (int i = 1; i < n; i++)
		v[i] = v[i-1] + ((s[i] == 'C') && (s[i-1] == 'A') ? 1 : 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << v[r-1] - v[l-1] << ende;
	}
  return 0;
}
