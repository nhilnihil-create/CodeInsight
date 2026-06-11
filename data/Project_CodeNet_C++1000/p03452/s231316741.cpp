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

const int MAX_N = 100050;
const ll INF = 1e18;
int n, m;
ll x[MAX_N];
bool vis[MAX_N];
vector<pair<int, ll> > adj[MAX_N];


bool dfs(int here) {
	vis[here] = true;

	if(x[here] == INF) {
		x[here] = 0;
	}

	for (auto it : adj[here]) {
		int there = it.F;
		ll d = it.S;

		if(vis[there]) {
			if(x[there] != x[here] + d) {
				return false;
			}
		} else {
			x[there] = x[here] + d;
			if(!dfs(there)) {
				return false;
			}
		}
	}

	return true;
}

void dfsAll() {
	rep(i,1,n+1) {
		if(!vis[i] && !dfs(i)) {
			cout << "No" << '\n';
			return;
		} 
	}
	cout << "Yes" << '\n';
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i,0,MAX_N) {
		x[i] = INF;
		vis[i] = false;
	}
	rep(i,0,m) {
		int L, R;
		ll D;
		cin >> L >> R >> D;
		adj[L].pb(mp(R,D));
		adj[R].pb(mp(L,-D));
	}
	dfsAll();
	return 0;
}
