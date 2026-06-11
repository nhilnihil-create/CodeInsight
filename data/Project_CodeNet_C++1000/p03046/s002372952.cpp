// copied by Nurstan Duisengaliev
// skatal
#include <bits/stdc++.h>
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) x.size()
 
using namespace std;
 
const int N = (int)2e5 + 123;
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
deque <int> d;
void solve () {
	int n, k;
	cin >> n >> k;	
	if (k > (1 << n) - 1) {
		cout << -1;
		return;
	}	
	if (k == 0) {
		int x = 0;
		for (int i = 1; i <= (1 << n); i ++) {
			cout << x << " " ;
			x ++;
		}
		x = (1 << n) - 1;
		for (int i = 1; i <= (1 << n); i ++) {
			cout << x << " ";
			x --;
		}
		return;
	}                
	if (n == 1) {
		cout << -1;
		return;
	}	
	d.pb (0);
	d.pb (k);
	d.pb (0);
	for (int i = 1; i <= (1 << n) - 1; i ++) {
		if (i != k) {
			d.pb (i);
			d.pf (i);
		}           
	}
	d.pb (k);
	for (int i = 0; i < sz (d); i ++) cout << d[i] << " ";
}
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//	cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}	