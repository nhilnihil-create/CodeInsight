#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
typedef pair<int, int> ii;
int n, a[N];
bool check(int x) {
	priority_queue<ii> pq; //{position, character}
	fw (i, 1, n) {
		if (a[i] > a[i - 1]) continue;
		while (!pq.empty()) {
			ii tmp = pq.top(); pq.pop();
			if (tmp.fi <= a[i]) {
				pq.push(tmp);
				break;
			}
		}
		//Top of pq is now <= a[i]. We increment position a[i] by 1
		int cur = a[i], save = 1;
		while (save) {
//			cout << "cur = " << cur << " size = " << pq.size() << "\n";
			if (!pq.size()) {
				pq.push(ii(cur, 2));
//				cout << "Push in (" << cur << ", 2)\n";
				save = 0;
			} else {
				ii tmp = pq.top(); pq.pop();
				if (tmp.fi == cur) {
					if (tmp.se < x) {
						tmp.se++;
						pq.push(tmp);
						save = 0;
					} else {
						if (tmp.fi == 1) return 0;
						save = 1; //Position is reset to 'a', therefore don't need storage.
					}
				} else {
//					cout << "Push in (" << cur << ", 2)\n";
					pq.push(tmp);
					pq.push(ii(cur, 2)), save = 0;
				}
			}
			cur--;
		}
	}
	return 1;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, n) cin >> a[i];
	bool inc = 1;
	fw (i, 1, n) if (a[i] <= a[i - 1]) {
		inc = 0;
		break;
	}
	if (inc) {
		cout << "1";
		return 0;
	}
//	If a[i + 1] > a[i], it's just a[i] padded with as
//	a[i + 1] <= a[i], position a[i + 1] of a[i] will be incremented by 1.
//	Use priority queue.
	int l = 2, r = n;
	while (l < r) {
		int m = (l + r) >> 1;
		if (check(m)) r = m;
		else l = m + 1;
	}
	cout << l;
	return 0;
}