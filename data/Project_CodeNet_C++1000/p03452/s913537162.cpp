// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

const int N=1e5+100;
vector<ii>gfo[N];
bool vst[N];
int d[N];
vector<int>ts;

void toposort(int u){
	vst[u]=true;
	for(ii v:gfo[u])
		if(!vst[v.ff])toposort(v.ff);
	ts.pb(u);
}

bool dfs(int u,int val){
	vst[u]=true;
	bool ctm=false;
	for(ii v:gfo[u]){
		if(d[v.ff]==-1)d[v.ff]=d[u]+v.ss;
		else{
			if(d[v.ff]!=d[u]+v.ss)return true;
		}
		if(!vst[v.ff])ctm|=dfs(v.ff,d[u]+v.ss);
	}
	return ctm;
}

int main(){	
	int n,m;cin>>n>>m;	
	For(i,0,m){
		int l,r,d;cin>>l>>r>>d;
		l--,r--;
		gfo[l].pb({r,d});
	}
	bool find=false;
	For(i,0,n)if(!vst[i])toposort(i);
	reverse(all(ts));
	memset(vst,false,sizeof(vst));
	memset(d,-1,sizeof(d));
	for(int u:ts)if(!vst[u]){
		d[u]=0;
		find|=dfs(u,0);
	}
	if(find)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
	return 0;
}
