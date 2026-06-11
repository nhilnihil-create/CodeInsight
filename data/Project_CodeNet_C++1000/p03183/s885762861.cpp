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
const int N = 2e4 + 10;

int dp[N];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int w[n + 1], s[n + 1], v[n + 1];
	vi ord;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> s[i] >> v[i];
		ord.pb(i);
	}
	sort(all(ord), [&](const int a, const int b) {return (s[a] + w[a]) < (s[b] + w[b]);});
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i : ord) {
		for(int j = s[i]; j >= 0; j--) {
			if(j + w[i] < N && dp[j] != -1) {
				dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
			}
		}
	}
	cout << *max_element(dp, dp + N);

	return 0;
}