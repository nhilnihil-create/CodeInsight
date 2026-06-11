# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define f first 
# define s second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

# define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
# define debug cerr<<"ERROR"<<endl
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int inf=1e9,mod=998244353,N=2e5+5;


void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	rep(i,n){
		cin>>a[i];
	}
	sort(all(a));
	int ans=inf;
	rep(i,n){
		if(i+k-1<n){
			umin(ans,a[i+k-1]-a[i]);
		}
	}
	cout<<ans;
}

int main(){
 	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}