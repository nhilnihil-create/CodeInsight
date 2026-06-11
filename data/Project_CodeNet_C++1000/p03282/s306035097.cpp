# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define f first 
# define s second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define pqueue priority_queue

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int mod=1e9+7,N=1e6+3;



void solve(){	
	string s;
	cin>>s;
	ll k;
	cin>>k;
	for(ll i=0;i<sz(s);++i){
		if(i+1==k){
			cout<<s[i];
			return;
		}
		if(s[i]!='1'){
			cout<<s[i];
			return;
		}
	}


}

int main(){
 	ios_base::sync_with_stdio(0);
 	cin.tie(0);cout.tie(0);
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}