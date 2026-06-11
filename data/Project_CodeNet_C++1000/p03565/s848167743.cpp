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

ll n,ans;

void solve(){
	string s,t;
	cin>>s>>t;
	string ans(sz(s),'z');
	bool has=0;
	for(int i=0;i<sz(s)-sz(t)+1;++i){
		bool ok=1;
		for(int j=0;j<sz(t);++j){
			if(s[i+j]!='?' && s[i+j]!=t[j]){
				ok=0;
				break;
			}
		}
		if(!ok)continue;
		if(ok)has=1;
		string zz=s;
		for(int j=0;j<sz(t);++j){
			if(zz[i+j]=='?' && zz[i+j]!=t[j]){
				zz[i+j]=t[j];
			}	
		}
		rep(i,sz(zz))if(zz[i]=='?')zz[i]='a';
		umin(ans,zz);
	}
	if(!has)cout<<"UNRESTORABLE";
	else cout<<ans;
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}