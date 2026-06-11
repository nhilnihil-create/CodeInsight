#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair <int, int> pii;

// template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//  order_of_key (k) : Number of items strictly smaller than k .
//  find_by_order(k) : K-th element in a set (counting from zero).
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define show(a) cerr << #a <<" -> "<< a <<"\n"
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))
//#define int ll

const int N = 105;
const int oo = 1e9 + 5;

bool edge[N][N];
int sum[N];

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		for (int i = 1; i < n; ++i) {
			edge[i][n] += i;
			edge[n][i] += i;
			sum[n] += i;
			sum[i] += n;
		}
		--n;
	}
	for (int i = 1, j = n; i < j; ++i, --j) {
		for (int k = 1; k <= n; ++k) {
			if (k == i || k == j) continue;
			edge[i][k] = 1;
			edge[k][i] = 1;
			sum[i] += k;
			edge[j][k] = 1;
			edge[k][j] = 1;
			sum[j] += k;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n+1; ++i) {
		for (int j = i + 1; j <= n+1; ++j) {
			if (edge[i][j]) ++cnt;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n+1; ++i) {
		for (int j = i + 1; j <= n+1; ++j) {
			if (edge[i][j]) {
				cout << i <<' '<< j << '\n';
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	while (tt --) {
		solve();
	}
	return 0;
}
/*
	If you only do what you can do, 
	You will never be more than you are now!
*/