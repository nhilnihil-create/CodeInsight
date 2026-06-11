/* 

	 - If you fail to prepare, you are prepared to fail.	

	(C) Mark Spitz

*/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define S second
#define F first
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;

const bool dbg_flg = 1;
#define NAME(x) #x
#define debug if (dbg_flg) cerr

const int inf = 1e9 + 7;
const int MAXN = 1e6 + 5;

int n;
vector<int> v;

void solve() {	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}
	
	vector<int> res;
		
	while (!v.empty()) {
		int pos = -1;
		
		for (int i = 0; i < sz(v); i++) {
			if (v[i] == i + 1) pos = i;
		}
		
		if (pos == -1) {
			cout << -1;
			return;
		}
		
		res.pb(v[pos]);
		
		v.erase(v.begin() + pos);
	}
	
	reverse(all(res));
	
	for (int i : res) {
		cout << i << '\n';
	}
}

int main() {
	
	//~ freopen(".in", "r", stdin);
	//~ freopen(".out", "w", stdout);
	                                                         
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt = 1;
	//~ cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}
