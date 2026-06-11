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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], cnt[MAXN][2];
bool mark[MAXN];
vector<int> G[MAXN];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		char ch;
		cin>>ch;
		A[i]=(ch=='B');
	}
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
		cnt[u][A[v]]++;
		cnt[v][A[u]]++;
	}
	for (int i=1; i<=n; i++) if (!cnt[i][0] || !cnt[i][1]) Q.push(i);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		ans++;
		for (int u:G[v]) if (!--cnt[u][A[v]]) Q.push(u);
	}
	if (ans==n) cout<<"No\n";
	else cout<<"Yes\n";
	
	return 0;
}
