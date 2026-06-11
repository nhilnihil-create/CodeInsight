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
const int MAXN = 1*1e5+5;

vector<int> g[MAXN];

int pai[MAXN], h[MAXN], ap[MAXN];

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return;
	
	if(h[a] == h[b]) {
		h[a]++;
		pai[b] = a;
		return;
	}
	if(h[a] < h[b])
		swap(a, b);
	pai[b] = a;
}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		pai[i] = i;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		join(a, b);
		
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) 
		if(ap[find(i)]++ == 0) ans++;
	cout << ans << endl;
	

}
