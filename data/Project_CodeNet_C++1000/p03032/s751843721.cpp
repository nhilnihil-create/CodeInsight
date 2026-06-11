#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }

void setOut(string s) { freopen(s.c_str(), "w", stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string &USACO_TAG) {
	setIn(USACO_TAG + ".in");
	setOut(USACO_TAG + ".out");
}

void print() {}

template<typename T, typename... Args>
void print(T firstArg, Args... args) {
	#ifdef LOCAL
	cout << firstArg << "\t";
	print(args...);
	#endif
}
//endregion

/* Notes:
 * Farah </3
 */

const int MAXN = 55;
const ll INF = 2e18;


ll a[MAXN];

int main() {
	#ifdef LOCAL
	setIn("in.txt");
	setOut("out.txt");
	#endif

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll ans = 0;
	for(int i = 1; i <= min(n, k); i++){
		vector<ll> left, right;

		for(int j = 0; j < i; j++){
			left.push_back(a[j]);
		}
		for(int j = -1; j < i; j++){
			if(j > -1) {
				left.pop_back();
				right.push_back(a[n - j - 1]);
			}

			vector<ll> v;
			for(auto x : left) v.push_back(x);
			for(auto x : right) v.push_back(x);

			sort(v.begin(), v.end());
			int idx = 0;
			for(int q = 0; q < (int) v.size() && idx < k - i; q++){
				if(v[idx] < 0){
					v[idx] = 0;
					idx++;
				}
			}
			ll sum = 0;
			for(auto x : v) sum += x;
			ans = max(ans, sum);
		}
	}
	cout << ans;
}
