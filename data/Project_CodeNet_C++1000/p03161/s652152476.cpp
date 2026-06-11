//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define bit(i) (1<<(i))
#define set(mask,i) (mask |= (1<<(i)))
#define get(mask,i) (mask & (1<<(i)))
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
const ll INF64 = (ll)1e15;
const int INF32 = (int)1e9;
const int64_t md = (int64_t)((int64_t)1e9 + 7);
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int& el : arr) cin >> el;
	int dp[n];
	for(int& el : dp) el = INF32;
	dp[0] = 0;
	for(int i = 1; i < n; i++) {
		for(int kk = 1; kk <= k; kk++) {
			if(i-kk >= 0) dp[i] = min(dp[i], dp[i-kk]+abs(arr[i]-arr[i-kk]));
		}
	}
	cout << dp[n-1];

	return 0;
}