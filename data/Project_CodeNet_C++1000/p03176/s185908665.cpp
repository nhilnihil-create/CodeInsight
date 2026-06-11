#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define int long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> mat;
const ll mod = 1e9+7;
const int MAXN = 2*1e5+5;

vector<int> h, b;

int bit[MAXN];

void update(int x, int u) {
	while(x < MAXN) {
		bit[x] = max(bit[x], u);
		x += x & -x;
	}
}

int query(int x) {
	int mx = 0;
	while(x > 0) {
		mx = max(bit[x], mx);
		x -= x & -x;
	}
	return mx;
}

int32_t main() {
	
	FAST;
	int n;
	cin >> n;
	h.resize(n);
	b.resize(n);
	
	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int &i : b)
		cin >> i;
	
	for(int i = 0; i < n; i++)
		update(h[i], query(h[i]-1) + b[i]);
			
	cout << query(MAXN-1) << endl;
}
