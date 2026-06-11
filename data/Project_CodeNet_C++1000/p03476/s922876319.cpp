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

int q,l,r,prime[N],pref[N];

void solve(){
	for(int i=2;i<=1e5;++i)prime[i]=1;
	//forn(i,100)cout<<prime[i]<<' ';
	for(int i=2;i<=1e5;++i){
		for(int j=i+i;j<=1e5;j+=i){
			prime[j]=0;
		}
	}
	for(int i=2;i<=1e5;++i){
		pref[i]=pref[i-1];
		//if(prime[i])cout<<i<<' '; 
		if(prime[i] && prime[(i+1)/2]){
			//cout<<i<<' ';
			++pref[i];
		}
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<pref[r]-pref[l-1]<<'\n';
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