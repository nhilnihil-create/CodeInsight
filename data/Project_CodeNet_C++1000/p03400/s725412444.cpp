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

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int inf=1e9,mod=1e9+7,N=2e5+5;

void solve(){
	int n,d,x;
	cin>>n>>d>>x;
	rep(i,n){
		int c;
		cin>>c;
		x+=(d+c-1)/c;
	}
	cout<<x;
	
}
int main(){
 	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}