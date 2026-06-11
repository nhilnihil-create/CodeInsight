//Dile a la jardinera que traigo flores
#include <bits/stdc++.h>

#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define trace(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = int(a); i < int(b); i++)
#define iFR(i,a) for(int i = int(a-1); i >= int(0); i--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int N=1e5+5;
vector<ii>gfo[N];int d[N];

inline void build(int n){
	FOR(i,1,n)FOR(j,0,10)
		gfo[i].pb(mp((10*i+j)%n,j));
}

inline int dijkstra(int n){
	priority_queue<ii,vector<ii>,greater<ii> >pq;
	FOR(i,0,N)d[i]=INT_MAX;
	FOR(i,1,10)if(d[i]>i){
		d[i]=i;pq.push(mp(i,i%n));
	}
	while(!pq.empty()){
		ii ini=pq.top();pq.pop();
		int dist=ini.fst;
		int u=ini.snd;
		if(dist>d[u])continue;
		for(ii v:gfo[u])if(d[u]+v.snd<d[v.fst]){
			d[v.fst]=d[u]+v.snd;
			pq.push(mp(d[v.fst],v.fst));
		}
	}
	return d[0];
}

int main(){
	int n;scanf("%d",&n);
	build(n);
	int res=dijkstra(n);
	cout<<res<<endl;
	return 0;
}