//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
short dp[330][330][330];
int n, k;
string s, t;
short f(int i, int j, int k) {
	if(k<0) return -3;
	if(i>j) return 0;
	if(i==j) return 1;
	if(dp[i][j][k] != -1) return dp[i][j][k];
	dp[i][j][k] = max(f(i+1,j,k), f(i,j-1,k));
	dp[i][j][k] = max(dp[i][j][k], (short)(f(i+1,j-1,k - (s[i]!=s[j])) + 2));
//	cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
	return dp[i][j][k];
//			dp[i][j][k] = max(dp[]);
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> k;
	memset(dp, -1, sizeof dp);
	cout << f(0, s.size()-1, k);
}
