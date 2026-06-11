#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define printarray(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout<<*it<<" "; cout<<endl;
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)
#define int long long int
#define ull unsigned long long

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int fastexpo(int b, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return b;
    int ans = (fastexpo(b,exp/2) % MOD);
    ans *= ans;
    ans %= MOD;
    if(exp % 2 == 1){
        ans *= b;
    }
    ans %= MOD;
    return ans;
}

vector<int> adj[MAXN];
int dp[MAXN][4];

int dfs(int s, int curr, int p){
	int ans = 1;
	int cnt = 0;
	if(dp[s][curr] != -1) return dp[s][curr];
	for(auto it: adj[s]){
		if(it == p){
			continue;
		}
		cnt++;
		if(curr == 1){
			ans *= (dfs(it, 0, s)%MOD);
			ans %= MOD;
		} else {
			ans *= ((dfs(it, 0, s)%MOD + dfs(it, 1, s)%MOD))%MOD;
			ans %= MOD;
		}
	}
	if(cnt == 0){
		return 1;
	}
  	ans %= MOD;
	return dp[s][curr] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    for(int i = 0;i<n-1;i++){
    	int t1, t2;
    	cin>>t1>>t2;
    	adj[t1].pb(t2);
    	adj[t2].pb(t1);
    }
    memset(dp, -1, sizeof(dp));
    cout<<(dfs(1, 1, -1) + dfs(1, 2, -1))%MOD<<endl;
    return 0;
}



