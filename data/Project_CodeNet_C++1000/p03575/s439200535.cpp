/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=5e5+10;
vector<int> g[MAXN];
int n,m,low[MAXN],deep[MAXN];
bool vis[MAXN];
void dfs(int now,int pre=0,int depth=0){
	low[now]=deep[now]=depth;
	vis[now]=1;
	for(auto it:g[now]){
		if(it!=pre){
			if(vis[it]){
				low[now]=min(low[now],deep[it]);
			}
			else{
				dfs(it,now,depth+1);
				low[now]=min(low[now],low[it]);
			}
		} 
	}
}
int main(){
	fastio;
	R2(n,m);
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	} 
	dfs(1);
	int res=0;
	rb(i,1,n){
		res+=(low[i]==deep[i]);	
	}
	res--;
	cout<<res<<endl;
	return 0;
}
/*
INPUT:
7 7
1 3
3 4
4 5
5 6
6 4
6 7
7 2
OUTPUT:
4
*/