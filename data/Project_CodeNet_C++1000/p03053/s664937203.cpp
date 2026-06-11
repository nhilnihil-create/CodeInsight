#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

vll dy4 = {-1,0,1,0} ;
vll dx4 = {0,1,0,-1} ;

int main(){
	ll h,w ;
	cin >> h >> w ;
	vvc g(h,vc(w)) ;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> g.at(i).at(j) ;
		}
	}
	vvll d(h,vll(w,-1)) ;
	queue<int> q ;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(g.at(i).at(j)=='#'){
				d.at(i).at(j) = 0 ;
				q.push(i) ;
				q.push(j) ;
			}
		}
	}
	auto check = [&](int y,int x,int dis){
		if(0<=y&&y<h&&0<=x&&x<w&&d.at(y).at(x)==-1){
			d.at(y).at(x) = dis ;
			q.push(y) ;
			q.push(x) ;
		}
	} ;
	while(!q.empty()){
		int y = q.front() ;
		q.pop() ;
		int x = q.front() ;
		q.pop() ;
		int dis = d.at(y).at(x)+1 ;
		for(int i=0;i<4;i++){
			check(y+dy4.at(i),x+dx4.at(i),dis) ;
		}
	}
	ll ans = 0 ;
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) ans = max(ans,d.at(i).at(j)) ;
	cout << ans << endl ;
}
