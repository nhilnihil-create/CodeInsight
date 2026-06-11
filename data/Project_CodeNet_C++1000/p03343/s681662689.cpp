#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for (int i = (int)a; i >= (int)b; i--)
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back

int n, k, q, A[2005], ans = 1e9+100;

int check(int g) {
	vector<int> v, vv;
	v.clear(); vv.clear();
	int pre = 0;
	FOR(i, 1, n+1) {
		if (A[i] >= g) vv.pb(A[i]);
		else {
			sort(vv.begin(), vv.end(), greater<int>());
			FOR(j, 1, i-pre-k) {v.pb(vv.back()); vv.pop_back();}
			vv.clear();
			pre = i;
		}
	}
	sort(v.begin(), v.end());
	if (v.size() < q) return 1e9+100;
	else return (v[q-1] - g);
}

int main() {
	cin >> n >> k >> q;
	FOR(i, 1, n) cin >> A[i];
	A[n+1] = -1;
	FOR(i, 1, n) ans = min(ans, check(A[i]));
	cout << ans;
}
