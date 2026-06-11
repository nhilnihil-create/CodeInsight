#include <bits/stdc++.h>
#define endl '\n'
#define fast_in ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp  make_pair
#define pb  push_back
#define  sz(x)   (int)x.size()
#define  all(x)  x.begin(), x.end()
#define	 allr(x)  x.rbegin(), x.rend()
#define  bit(x)  __builtin_popcountll(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
const int inf = (int) 1e9+99999, mod = (int)1e9+7;
const ll linf = (ll) 2e18+99999;
int mul (int x, int y) { return ((ll)x * y) % mod; } 
int sub (int x, int y) { x -= y; if (x < 0) return x + mod; return x; } 
int add (int x, int y) { x += y; if (x >= mod) return x - mod; return x; }
 
const int maxn = (int) 3e5;
 
void solve () {
	string s; cin >> s;
	string t; cin >> t;
	int id = -1;
	for (int i = 0; i < sz (s); i ++) {
		bool ok = true;
		for (int j = 0; j < sz (t); j ++) {
			if (i + j == sz (s)) {
				ok = false;
				break;
			}
			if (s[i + j] == t[j]) continue;
			if (s[i + j] == '?') continue;
			ok = false;
			break;
		}
		if (ok) id = i;
	}

	if (id == -1) {
		cout << "UNRESTORABLE";
	} else {
		int c = 0;
		for (int i = id;; i ++) {
			s[i] = t[c];
			c ++; 
			if (c == sz (t)) break;
		}
		for (int i = 0; i < sz (s); i ++)
			if (s[i] == '?')
				s[i] = 'a';

		cout << s;
	}
}

main () { fast_in;
    int t = 1; //cin >> t;
    while (t --) {
    	solve ();    
    }
	return 0;
}