#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
#define f(z) for(int i=1;i<=z;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define pb push_back
#define si set<int>
int cl(int n ,int m) { if(n%m)return n/m + 1 ;else return n/m ;}
int pw(int a,int b){int r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
#define mod  1000000007
#define T() int TT; cin>>TT; while(TT--)
#define P pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e6 + 5 ;
vector<set<int> > g(N) ;
set<P> s ;
vi deg(N) , a(N) , ans(N);
signed main(){
	int n ,x ,y ; 
	cin >> n ;
	f(n-1){
		cin >> x >> y ;
		g[x].insert(y) ;
		g[y].insert(x) ;

		deg[x]++ , deg[y]++ ;
	}
	f(n) cin >> a[i] ; 
	f(n) s.insert({deg[i] ,i}) ;

	sort( a.begin()+1 , a.begin()+n+1) ;
	int add = 0;
	for ( int i = 1 ;i<=n ;i++){
		if(s.size() == 0 ) break ;
		int x = s.begin()->first ;
		int y = s.begin()->second ;
		s.erase(s.begin()) ;
		

		ans[y] = a[i] ;

		for ( auto it : g[y]){
			s.erase(s.find({deg[it] ,it})) ;
			deg[it]-- ;
		    s.insert({deg[it] , it}) ;

			g[it].erase(y) ;
			add += a[i] ; 
		}
	}

	cout << add << endl ;
	f(n) cout << ans[i] <<" " ;
}