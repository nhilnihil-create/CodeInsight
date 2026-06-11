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
const ll N = 1e5+4;

int n,m,p[N],y[N],cnt[N],has[N];
string that[N];
vector<int>g[N];

string make(int n){
	string s="000000";
	string g="";
	while(n){
		g+=char(n%10+'0');
		n/=10;
	}
	reverse(all(g));
	s+=g;
	return s.substr(sz(s)-6,6);
}

void solve(){
	cin>>n>>m;
	vector<pii>v;
	forn(i,m){
		cin>>p[i]>>y[i];
		g[p[i]].pb(y[i]);
	}
	forn(i,n){
		sort(all(g[i]));
	}
	forn(i,m){
		if(!has[p[i]]){
			that[p[i]]=make(p[i]);
			has[p[i]]=1;
		}
		cout<<that[p[i]];
		cout<<make(lb(all(g[p[i]]),y[i])-g[p[i]].begin()+1);
		cout<<'\n';
	}
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}