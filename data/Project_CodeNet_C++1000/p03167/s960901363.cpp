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
const int64_t INF64 = (int64_t)1e18;
const int INF32 = (int)1e9 + (int)1e8;
const int64_t md = (int64_t)((int64_t)1e9 + 7);
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
 	int r, c;
 	cin >> r >> c;
 	string arr[r];
 	for(int i = 0; i < r; i++) {
 		cin >> arr[i];
 	}
 	// dp[i][j] is number of path to cell [r][c] starting from cell [i][j];
 	int64_t dp[r+1][c+1];
 	for(int i = 0; i <= r; i++) {
 		for(int j = 0; j <= c; j++) {
 			dp[i][j] = 0;
 		}
 	}
 	dp[r-1][c-1] = 1;
 	for(int i = r-1; i >= 0; i--) {
 		for(int j = c-1; j >= 0; j--) {
 			if(i == r-1 && j == c-1) continue;
 			if(arr[i][j] == '#') {dp[i][j] = 0; continue;}
 			dp[i][j] += (dp[i][j+1]%md);
 			dp[i][j] += (dp[i+1][j]%md);
 		}
 	}
 	cout << dp[0][0]%md;
 
	return 0;
}