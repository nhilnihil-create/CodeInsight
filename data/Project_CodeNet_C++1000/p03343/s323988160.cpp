#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

const int N = 2e3+3;

int n, k, q;
int a[N];
int res = INT_MAX;

#define x first
#define y second

typedef tree<pair<int, int>,null_type,less< pair< int, int > >,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
order_set X;

void dothething(int pos) {
	// cout << '\n';
	int c = 0;
	X.clear();
	multiset<int> tem;
	for (int i = 1; i <= n+1; i++) {
		// cout << tem.size() << " ";
		if (a[i] < a[pos]) {
			while (!tem.empty()) {
				if (tem.size() >= k) {
					c++;
					X.insert({*tem.begin(), c});
				}
				tem.erase(tem.begin());
			}
		}
		else {
			tem.insert(a[i]);
		}
	}	
	if (X.size() >= q) {
		res = min(res, abs(a[pos] - (*X.find_by_order(q-1)).x));
	}
}

signed main() {
	scanf("%d%d%d", &n, &k, &q);
	a[n+1] = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		dothething(i);
	}
	cout << res;
}