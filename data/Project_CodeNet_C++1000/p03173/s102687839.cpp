#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
const int maxn = 100005;
ll dp[400][400];
vector<ll>p;
vector<ll>v;
ll solve(int l, int r) {
	if (~dp[l][r]) {
		return dp[l][r];
	}
	if (l == r) {
		return dp[l][r] = v[l];
	}
	ll mi = 1e18;
	for (int i = l ; i < r; i++) {
		mi = min(mi, solve(l, i) + solve(i + 1, r) + p[r + 1] - p[l]);
	}
	return dp[l][r] = mi;
}
void go() {
	int n;
	cin >> n;
	p.pb(0);
	f(n) {
		int x;
		cin >> x;
		v.pb(x);
		p.pb(p.back() + v.back());
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n - 1) - p[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}