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



int32_t main() {
	int m, k;
	cin >> m >> k;
	if (k >= (1 << m)) {
		cout << -1 << endl;
		return 0;
	}
	if (m == 1) {
		if (k == 1) {
			cout << -1 << endl;
			return 0;
		}
		else {
			cout << "0 0 1 1" << endl;
			return 0;
		}
	}
	
	int n = (1<<m);
	
	vector<int> ans;
	for(int i = 0; i < n; i++)
		if(i != k)
			ans.pb(i);
	ans.pb(k);
	
	for(int i = n-1; i >= 0; i--)
		if(i != k)
			ans.pb(i);
			
	ans.pb(k);

	for(auto i : ans) cout << i << " ";
	cout << endl;
}
