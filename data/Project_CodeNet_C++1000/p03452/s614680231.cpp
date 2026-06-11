#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int E[MAXN][3];
int sum[MAXN];
bool mark[MAXN];
vector<pii> G[MAXN];

void dfs(int node){
	mark[node]=1;
	for (pii p:G[node]) if (!mark[p.first]){
		sum[p.first]=sum[node]+p.second;
		dfs(p.first);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>E[i][0]>>E[i][1]>>E[i][2];
		G[E[i][0]].pb({E[i][1], E[i][2]});
		G[E[i][1]].pb({E[i][0], -E[i][2]});
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfs(i);
	for (int i=1; i<=m; i++){
		if (sum[E[i][1]]-sum[E[i][0]]!=E[i][2]) kill("No")
	}
	kill("Yes")
	
	return 0;
}
