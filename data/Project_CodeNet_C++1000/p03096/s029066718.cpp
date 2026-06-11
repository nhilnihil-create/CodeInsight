#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // order_of_key, find_by_order
ll mod = 1e9+7, dp[200100], cnt[200200];

int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll n;
	 vi c;
	 cin >> n;
	 c.resize(n);
	 for(auto &i : c) cin >> i;
	 for(int i = 0; i < n; i++) {
		 if(i&&c[i]==c[i-1]) {dp[i]=dp[i-1];continue;}
		 dp[i] = (cnt[c[i]]+(i?dp[i-1]:1))%mod;
		 cnt[c[i]] = (cnt[c[i]]+(i?dp[i-1]:1))%mod;
	 }
	 cout << dp[n-1];
}
