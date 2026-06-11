#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vll p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;
	map<ll,ll> m ;
	for(int i=0;i<p.size();i++){
		ll num = p.at(i) ;
		m[p.at(i)] = 0 ;
		while(num<=n){
			m[p.at(i)] += n/num ;
			num *= p.at(i) ;
		}
	}
	vll cnt(100,0) ;
	for(int i=0;i<p.size();i++) cnt.at(m[p.at(i)])++ ;
	for(int i=cnt.size()-2;i>=0;i--) cnt.at(i) += cnt.at(i+1) ;
//	for(auto i:cnt) cout << i << " " ; cout << endl ;
//	cout << m[31] << endl ;
	ll ans = 0 ;
	ans += cnt.at(74) ;
	ans += cnt.at(24)*(cnt.at(2)-1) ;
	ans += cnt.at(14)*(cnt.at(4)-1) ;
	ans += cnt.at(4)*(cnt.at(4)-1)*(cnt.at(2)-2)/2 ;
	cout << ans << endl ;
}
