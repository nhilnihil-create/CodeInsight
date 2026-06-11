
/**
*	author: Shaurya Bagga
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long double ld;

#define endl "\n"

const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 10;
const double PI = 3.1415926;
const ll INF = 1e18;
const double EPS = 1e-5;

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x,y,z,k; cin >> x >> y >> z >> k;
	vector<ll> a(x, 0), b(y, 0), c(z, 0);
	for(int i = 0; i < x; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < y; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < z; ++i) {
		cin >> c[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end(), greater<ll>());
	sort(c.begin(), c.end(), greater<ll>());
	vector<ll> all;
	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j) {
			for(int h = 0; h < z; ++h) {
				if ((i + 1) * (j + 1) * (h + 1) > k) break;
				all.push_back(a[i]+b[j]+c[h]);
			}
		}
	}
	sort(all.begin(), all.end(), greater<ll>());
	for(int i = 0; i < k; ++i) {
		cout << all[i] << endl;
	}
	return 0;
}
