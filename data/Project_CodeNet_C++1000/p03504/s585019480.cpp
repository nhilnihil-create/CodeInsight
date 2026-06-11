#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
#include <utility>
//#include <set>
//#include <map>
//#include <queue>
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
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,c ;
	cin >> n >> c ;
	vector<vector<pll>> tv(c,vector<pll>(0)) ;
	for(int i=0;i<n;i++){
		ll s,t,ch ;
		cin >> s >> t >> ch ;
		s-- ; t-- ; ch-- ;
		tv.at(ch).emplace_back(s,t) ;
	}
	for(int i=0;i<c;i++) tv.at(i).emplace_back(INF,INF) ;
	for(int i=0;i<c;i++) sort(all(tv.at(i))) ;
	vll time(100100,0) ;
	for(int i=0;i<c;i++){
		ll s = tv.at(i).at(0).first ;
		ll t = tv.at(i).at(0).second ;
		for(int j=1;j<tv.at(i).size();j++){
			if(tv.at(i).at(j).first!=t){
				time.at(s)++ ;
				time.at(t+1)-- ;
				s = tv.at(i).at(j).first ;
				t = tv.at(i).at(j).second ;
			}else{
				t = tv.at(i).at(j).second ;
			}
		}
	}
	for(int i=1;i<time.size();i++) time.at(i) += time.at(i-1) ;
	ll ans = 0 ;
	for(int i=0;i<time.size();i++) ans = max(ans,time.at(i)) ;
	cout << ans << endl ;
//	for(auto i:tv){
//		for(auto j:i){
//			cout << j.first << " " << j.second << " " ;
//		}
//		cout << endl ;
//	}
}
