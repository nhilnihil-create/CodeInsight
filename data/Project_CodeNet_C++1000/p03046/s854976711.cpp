#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;

typedef tree <pii, null_type, less <pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int m, k;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> m >> k;
	if (m == 0) {
		if (k == 0) {
			cout << "0 0";
		}	else {
			cout << -1;
		}
		return 0;
	}
	if (m == 1) {
		if (k == 0) {
			cout << "0 0 1 1";
		}	else {
			cout << -1;
		}
		return 0;
	}
	if (k >= (1 << m)) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < (1 << m); i++) {
		if (i != k) {
			cout << i << ' ';
		}
	}
	cout << k << ' ';
	for (int i = (1 << m) - 1; i >= 0; i--) {
		if (i != k) {
			cout << i << ' ';
		}
	}
	cout << k;
}
