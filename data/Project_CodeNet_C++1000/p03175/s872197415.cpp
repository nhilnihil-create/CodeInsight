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
ll dp[maxn][2];
vector<int>g[maxn];
void dfs(int now, int pre) {
	ll m0 = 1, m1 = 1;
	for (auto &i : g[now]) {
		if (i ^ pre) {
			dfs(i, now);
			m0 *= (dp[i][0] + dp[i][1]) % mod;
			m0 %= mod;
			m1 *= dp[i][0] ;
			m1 %= mod;
		}
	}
	dp[now][0] = m0;
	dp[now][1] = m1;
	//cout << now <<' '<<dp[now][0] <<' '<<dp[now][1] << endl;
}
void go() {
	int n;
	cin >> n;
	f(n-1) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0);
	cout << (dp[1][0] + dp[1][1]) % mod << '\n';
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