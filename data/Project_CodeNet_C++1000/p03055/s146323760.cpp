#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=200005;
const int MOD=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())

int N;
vector<int>adj[MAXN];
int dist[MAXN];
void dfs(int v, int p, int d){
	dist[v]=d;
	for(auto i:adj[v])if(i!=p)dfs(i,v,d+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	FOR(i,1,N-1){
		int a,b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1,-1,0);
	int v1=1;
	FOR(i,1,N)if(dist[v1]<dist[i])v1=i;
	dfs(v1,-1,0);
	int v2=v1;
	FOR(i,1,N)if(dist[v2]<dist[i])v2=i;
	//~ cout<<v1<<' '<<v2<<"\n";
	if(dist[v2]%3==1)cout<<"Second\n";
	else cout<<"First\n";
}
/*
3
2 5
6 1
3 7
Ans:6

4
3 7
2 9
8 16
10 8
Ans:9
*/
