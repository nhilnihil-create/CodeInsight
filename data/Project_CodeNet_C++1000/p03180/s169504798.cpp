#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 
#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
 
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
  
#define pb push_back
#define mp make_pair
#define in insert
#define f first
#define s second
#define ll long long
#define dd double
  
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int inf = 2e9;
const ll INF = 1e18;

ll a[20][20], dp[N], pr[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("*.in", "r", stdin);freopen("*.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((1 << j) & i) {
				for (int k = j; k < n; k++) {
					if ((1 << k) & i) {
						pr[i] += a[j][k];
					}
				}
			}
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = i; j; j = (j - 1) & i) {
			dp[i] = max(dp[i], dp[(i ^ j)] + pr[j]);
		}
	}

	cout << dp[(1 << n) - 1];
}