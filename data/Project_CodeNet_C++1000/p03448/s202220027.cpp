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
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	int ans=0;
	for(int i=0;i<=a;++i){
		for(int j=0;j<=b;++j){
			for(int k=0;k<=c;k++){
				if(i*500+j*100+k*50==x)ans++;
			}
		}
	}
	printf("%d",ans);

}

int main(){
 	ios_base::sync_with_stdio(0);
 	cin.tie(0);cout.tie(0);
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}