/*

    Bismillahirrahmanirrahim
	If you want something you never had, you must be willing to do what you have never done.

*/
                                          
#include <bits/stdc++.h>

#define st first
#define nd second
#define B begin()
#define E end()
#define sz size()
#define pb push_back
#define mp make_pair 
#define respa return 0

using namespace std;
typedef long long ll;

const int N = 1e6 + 17, mod = 1e9 + 7;

int tt = 1, n, b[N];
bool u[N];

void solve () {
	scanf("%d", &n);
	vector <int> v, ans;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		v.pb(b[i]);
	}
	reverse(v.B, v.E);
	while (!v.empty()) {
		bool ok = 0;
		for (int i = 0; i < v.sz; i++) {
			if (v[i] == v.sz - i) {
				ok = 1;
				ans.pb(v[i]);
				v.erase(v.B + i);
				break;
			}
		}
		if (!ok) {
			printf("-1");
			return;
		}
	}
	reverse(ans.B, ans.E);
	for (auto i : ans) {
		printf("%d \n", i);
	}
}

int main () {
	// scanf("%d", &tt);
	while (tt--) solve();
	respa;
}
