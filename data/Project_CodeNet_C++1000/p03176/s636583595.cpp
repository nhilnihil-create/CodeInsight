#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int n, bit[N];

void update(int idx, int val) {
	while(idx <= n) {
		bit[idx] = max(bit[idx], val);
		idx += idx & -idx;
	}
}

int prefMax(int idx) {
	int ans = -2e9;
	while(idx > 0) {
		ans = max(ans, bit[idx]);
		idx -= idx & -idx;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	int h[n + 1], a[n + 1];
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(h[i] == 1) {
			update(h[i], a[i]);
		}
		else {
			int mx = prefMax(h[i] - 1);
			update(h[i], mx + a[i]);
		}
	}
	cout << prefMax(n);

	return 0;
}