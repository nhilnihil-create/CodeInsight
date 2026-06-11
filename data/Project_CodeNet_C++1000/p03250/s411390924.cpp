#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int a[3];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 3; i++) cin >> a[i];
	sort(a, a + 3, greater<int>());
	cout << a[0] * 10 + a[1] + a[2] << "\n";
	return 0;
}