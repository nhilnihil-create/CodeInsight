#include <bits/stdc++.h>

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pii pair<int, int>
#define mp make_pair
#define f first
#define ll long long
#define s second
#define vec vector<int>

using namespace std;

const int N = (int) 3e5 + 10;
const int M = (int) 1e6 + 10;
const int K = (int) 500 + 10;
const int mod = (int) 998244353;

int n;
int l[N], r[N];
bool used[N];

ll get(int dir) {
	set<pii> st_l, st_r;
	for (int i = 1; i <= n; i++) {
		st_l.insert(mp(l[i], i));
		st_r.insert(mp(r[i], i));
	}
	int cur_pos = 0;
	ll cur = 0;
	for (int iter = 1; iter <= n; iter++) {
		int nxt = -1;
		if (dir) {
			// taking maximum l, saving index to nxt
			nxt = (--st_l.end()) -> s;
		} else {
			nxt = (*st_r.begin()).s;
			// taking minimum r, saving index to nxt
		}
		if (cur_pos > r[nxt]) {
			cur += cur_pos - r[nxt];
			cur_pos = r[nxt];
		} else if (cur_pos < l[nxt]) {
			cur += l[nxt] - cur_pos;
			cur_pos = l[nxt];
		} 
		st_l.erase(mp(l[nxt], nxt));
		st_r.erase(mp(r[nxt], nxt));
		dir ^= 1;
	}
	cur += abs(cur_pos);
	return cur;
}

int main() {
	#ifdef sony
		freopen("input.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif
	srand(time(0));
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	cout << max(get(0), get(1));
	return 0;
}