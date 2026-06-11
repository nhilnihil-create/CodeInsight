#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(z) for(int i=1;i<=z;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define pb push_back
#define si set<int>
#define mod  1000000007
#define cl(n,m) (n-1)/m  + 1 ;
#define T() int TT; cin>>TT; while(TT--)
#define P pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int  N = 1e5 + 5;
vector<P> v[N] ;
int dis[N] ;
void dj( int st){
	set<P> s ;
	s.insert({0,st}) ;
	dis[st] = 0 ;
	while( s.empty() == false){
		int ss = s.begin()->second ;
		s.erase( s.begin()) ;
		for( auto it : v[ss]) {
			if( dis[it.first] > dis[ss] + it.second){
				s.erase( {dis[it.first ] , it.first}) ;
				dis[it.first] = dis[ss] + it.second ;
				s.insert( {dis[it.first] , it.first}) ;
			}
		}
	}
}
signed main(){
	int n; 
	cin >>n ;
	rep(i , 0 , 100000 ) dis[i] = N ;
	for( int i = 1; i<=n ;i++){
		v[i%n].pb({(i+1)%n , 1}) ;
		v[i%n].pb( {(i*10)%n , 0}) ;
	}

	dj(1) ;
	cout << dis[0] + 1 ;
}