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

template<class T> void umin(T &a, T b) { a = min(a, b); }
template<class T> void umax(T &a, T b) { a = max(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e5+5;

int n,m;
ll ans;
void solve(){
	cin>>n>>m;
	vector<pii>v;
	forn(i,n){
		int x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	sort(all(v));
	rep(i,n){
		if(!m)break;
		if(m-v[i].S>=0){
			m-=v[i].S;
			ans+=v[i].S*1LL*v[i].F;	
		}
		else{
			ans+=v[i].F*1LL*m;
			m=0;
		}
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