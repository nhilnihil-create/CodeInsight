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


set<char> pref[N],suf[N];

void solve(){
	int n;
	cin>>n;	
	string s;
	cin>>s;
	int ans=0;
	//int n=sz(s);
	set<char>st;
	for(int i=0;i<n;++i){
		st.insert(s[i]);
		pref[i]=st;
	}
	st.clear();
	for(int i=n-1;i>=0;i--){
		st.insert(s[i]);
		suf[i]=st;
	}
	for(int i=1;i<n;++i){
		int cnt=0;
		for(auto j:pref[i-1]){
			if(suf[i].count(j))cnt++;
		}
		umax(ans,cnt);
	}
	cout<<ans;



}

int main(){
 	ios_base::sync_with_stdio(0);
 	cin.tie(0);cout.tie(0);
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}