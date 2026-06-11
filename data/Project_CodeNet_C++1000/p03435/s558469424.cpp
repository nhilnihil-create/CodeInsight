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
	int c[3][3];
	rep(i,3)rep(j,3)cin>>c[i][j];
	for(int a1=0;a1<=100;a1++){
		set<int>b[3];
		rep(i,3){
			b[i].insert(c[0][i]-a1);
		}
		for(int a2=0;a2<=100;a2++){
			bool ok=0;
			rep(j,3){
				if(!b[j].count(c[1][j]-a2)){
					ok=1;
					break;
				}
			}
			if(ok)continue;
			for(int a3=0;a3<=100;a3++){
				ok=0;
				rep(k,3){
					if(!b[k].count(c[2][k]-a3)){
						ok=1;
					}
				}
				if(ok)continue;
				cout<<"Yes";
				return;
			}
		}
	}
	cout<<"No";
}

int main(){
 	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}