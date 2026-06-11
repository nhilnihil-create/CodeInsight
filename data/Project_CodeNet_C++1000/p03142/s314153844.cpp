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
//using vc = vector<char> ;
//using vvc = vector<vc> ;
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

int main(){
	ll n,m ;
	cin >> n >> m ;
	vll cnt(n,0) ;
	vvll g(n) ;
	for(int i=0;i<n-1+m;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g.at(a).push_back(b) ;
		cnt.at(b)++ ;
	}
//	for(auto i:cnt) cout << i << endl ;
	queue<int> q ;
	vll d(n,-1) ;
	int root ;
	for(int i=0;i<n;i++){
		if(cnt.at(i)==0){
			q.push(i) ;
			d.at(i) = 0 ;
			root = i ;
		}
	}
	while(!q.empty()){
		int p = q.front() ;
		q.pop() ;
//		if(d.at(p)!=-1&&p!=root) continue ;
		for(int i=0;i<g.at(p).size();i++){
			if(cnt.at(g.at(p).at(i))==1){
//				cout << p << " " << g.at(p).at(i) << " " << cnt.at(g.at(p).at(i)) << endl ;
				q.push(g.at(p).at(i)) ;
				d.at(g.at(p).at(i)) = d.at(p)+1 ;
			}
			cnt.at(g.at(p).at(i))-- ;
		}
//		cout << q.size() << endl ;
	}
	vvll ans(n) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<g.at(i).size();j++){
			if(d.at(g.at(i).at(j))-d.at(i)==1){
				ans.at(i).push_back(g.at(i).at(j)) ;
			}
		}
	}
	vll par(n,-1) ;
	q.push(root) ;
	while(!q.empty()){
		int p = q.front() ;
		q.pop() ;
		for(int i=0;i<ans.at(p).size();i++){
			par.at(ans.at(p).at(i)) = p ;
			q.push(ans.at(p).at(i)) ;
		}
	}
	for(int i=0;i<n;i++) cout << par.at(i)+1 << endl ;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<ans.at(i).size();j++){
//			cout << i << " " << ans.at(i).at(j) << endl ;
//		}
//	}
//	for(int i=0;i<n;i++) cout << d.at(i) << endl ;
}
