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
	int k, n;
	vi h;
	cin >> n >> k;
	while (n--) {
		int e; cin >> e;
		h.pb(e);
	}
	sort(all(h));
	ll ans = 1123456789;
	for (int i = 0; i < h.size()-k+1; i++) 
		if (h[i+k-1]-h[i] < ans) ans = h[i+k-1]-h[i];
	cout << ans << ende;
	//0  1  2  3  4
	//5  5  7  7  7
  return 0;
}
