# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define mset multiset
# define umap unordered_map
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 55;

int n,m,u[N],v[N],used[N];
set<int>g[N];

void dfs(int x){
	used[x]=1;
	for(auto i:g[x]){
		if(!used[i])
			dfs(i);
	}
}

void solve(){
	cin>>n>>m;
	rep(i,m){
		cin>>u[i]>>v[i];
		g[u[i]].insert(v[i]);
		g[v[i]].insert(u[i]);
	}
	int ans=0;
	rep(i,m){
		g[u[i]].erase(v[i]);
		g[v[i]].erase(u[i]);
		for(int i=1;i<=n;++i)used[i]=0;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(!used[i]){
				dfs(i);
				cnt++;
			}
		}
		if(cnt>1){
			ans++;
			//cout<<u[i]<<' '<<v[i]<<'\n';
		}
		g[u[i]].insert(v[i]);
		g[v[i]].insert(u[i]);
	}
	cout<<ans;

}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}