#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> ans;
	while (!a.empty()) {
		n = a.size();
		bool ok = false;
		for (int j = n - 1; j >= 0; j--) {
			if (a[j] == j + 1) {
				ans.pb(a[j]);
				a.erase(a.begin() + j);
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << -1;
			return 0;
		}
	}
	reverse(all(ans));
	for (int i : ans) {
		cout << i << '\n';
	}
}
