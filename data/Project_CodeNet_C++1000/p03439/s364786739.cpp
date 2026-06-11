// IOI 2021
 
#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const int MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int RES[N];

int Ask(int i) {
	if (RES[i] != -1) return RES[i];
	cout << i << endl;
	string s; cin >> s;
	if (s == "Male") return RES[i] = 1;
	if (s == "Female") return RES[i] = 2;
	exit(0);
	return RES[i] = 0;
}

int Find(int l, int r) {
	if (Ask(l) == 0) return l;
	if (Ask(r) == 0) return r;
	int md = (l + r) >> 1;
	if (Ask(l) == Ask(md) && (md - l) % 2 == 1) return Find(l, md);
	if (Ask(l) != Ask(md) && (md - l) % 2 == 0) return Find(l, md);
	if (Ask(md) == Ask(r) && (r - md) % 2 == 1) return Find(md, r);
	if (Ask(md) != Ask(r) && (r - md) % 2 == 0) return Find(md, r);
	return -1;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) RES[i] = -1;
	Find(0, n - 1);

	return 0;
}
