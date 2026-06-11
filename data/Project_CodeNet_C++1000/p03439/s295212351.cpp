#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	/*cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);*/

	int n;
	cin >> n;
	cout << 0 << endl;
	int left = 0, right = n, mid;
	string t;
	cin >> t;
	vector<int> check(n);
	if (t == "Vacant") return 0;
	if (t == "Male") check[0] = 0;
	else check[0] = 1;
	rep(_, 30) {
		mid = (left + right) / 2;
		cout << mid << endl;
		string s;
		cin >> s;
		if (s == "Vacant") return 0;
		if (s == "Male") {
			if (check[left] == 0 && (left + mid) & 1) right = mid;
			else if (check[left] == 1 && !((left + mid) & 1)) right = mid;
			else left = mid;
			check[mid] = 0;
		}
		else {
			if (check[left] == 1 && (left + mid) & 1) right = mid;
			else if (check[left] == 0 && !((left + mid) & 1)) right = mid;
			else left = mid;
			check[mid] = 1;
		}
	}
}