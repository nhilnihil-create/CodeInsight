#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_N = 200050;
int n;
vi adj[MAX_N];
bool vis[MAX_N];
int diameter = 0;

int dfs(int here) {
	vis[here] = true;
	vector<int> heights;
	for(auto there : adj[here]) {
		if(!vis[there]) {
			heights.pb(dfs(there));
		}
	}
	if(heights.empty()) return 0;
	sort(all(heights));
	if(heights.size() >= 2) {
		diameter = max(diameter, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
	}
	return heights.back()+1;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i,0,n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	memset(vis, false, sizeof(vis));
	int height = dfs(0);
	diameter = max(diameter, height);
	bool dp[MAX_N];
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	dp[1] = false;
	rep(i,2,diameter+1) {
		dp[i] = !dp[i-1] || !dp[i-2];
	}
	if(dp[diameter]) {
		cout << "First" << '\n';
	} else {
		cout << "Second" << '\n';
	}
	return 0;
}
