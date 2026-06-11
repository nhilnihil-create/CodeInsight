#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repF(i,a,n) for(int i = (a); i <= (n); ++i)
#define repB(i,a,n) for(int i = (a); i >= (n); --i)
#define umii unordered_map<int,int>
#define umll unordered_map<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define F first
#define S second
#define seti set<int>
#define setl set<ll>
#define pb push_back
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbV(arr) cout << #arr << "=[ "; \
for(auto i:arr) cout << i << " "; cout << "]\n";
#define MOD 1000000007
#define all(z) z.begin(),z.end()
using namespace std;
using ll = long long;
vector<vi> tree;
vi dp;
int solve(vi &arr, int n) {
	if (n == 1) {
		return dp[n] = 0;
	}
	if (n == 2) {
		return dp[n] = abs(arr[n] - arr[n - 1]);
	}
	int n_1;
	if (dp[n - 1] != -1) {
		n_1 = dp[n - 1];
	}
	else {
		n_1 = solve(arr, n - 1);
	}
	int n_2;
	if (dp[n - 2] != -1) {
		n_2 = dp[n - 2];
	}
	else {
		n_2 = solve(arr, n - 2);
	}
	return dp[n] = min(abs(arr[n] - arr[n - 1]) + n_1,
	                   abs(arr[n] - arr[n - 2]) + n_2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	dp.assign(n + 1, -1);
	vi arr(n + 1); repF(i, 1, n) cin >> arr[i];
	//dp[n] = min(abs(arr[n]-arr[n-1])+dp[n-1], abs(arr[n]-arr[n-2])+dp[n-2]);
	cout << solve(arr, n) << endl;
	return 0;
}

