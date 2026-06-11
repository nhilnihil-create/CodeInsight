#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define S second
#define F first
#define all(x) (x).begin(), (x).end()


using namespace std;

const bool dbg_flg = false;
#define debug(x) if (dbg_flg) cerr << #x << ' ' << x << '\n'
#define debug_pair(x) if (dbg_flg) cerr << #x << ' ' << x.F << ' ' << x.S << '\n'
 
const int inf = 1e9 + 7;
const int MAXN = 1e6 + 5;
const ll INF = 1e18;

#define int ll

int n, m;
char s[MAXN], t[MAXN];
map<int, int> x;

main() {
	//~ freopen("input.txt", "r", stdin);
	//~ freopen("output.txt", "w", stdout);
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	
	int l = (n * m) / __gcd(n, m);
		
	if (s[0] != t[0]) {
		cout << -1;
		return 0;
	}
		
	for (int i = 1; i < n; i++) {
		int id = i * (l / n) + 1;
		x[id] = i;
	}
	
	for (int i = 1; i < m; i++) {
		int id = i * (l / m) + 1;
		
		if (x.find(id) != x.end()) {
			if (s[x[id]] != t[i]) {
				cout << -1;
				return 0;
			}
		}
		
		x[id] = i;
	}
	
	cout << l;
	return 0;
}