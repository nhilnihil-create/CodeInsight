#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
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
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll cnt(64,0) ;
	for(int i=0;i<n;i++){
		ll a ; cin >> a ;
		for(int j=0;j<64;j++) if((a>>j)&1) cnt.at(j)++ ;
	}
	vll dp1(64,-1),dp2(64,0) ;
	dp2.at(63) = 0 ;
	for(int i=45;i>=0;i--){
		if((k>>i)&1){
			if(dp1.at(i+1)!=-1) dp1.at(i) = dp1.at(i+1)+max(cnt.at(i),n-cnt.at(i))*(1LL<<i) ;
			dp1.at(i) = max(dp1.at(i),dp2.at(i+1)+cnt.at(i)*(1LL<<i)) ;
			dp2.at(i) = dp2.at(i+1)+(n-cnt.at(i))*(1LL<<i) ;
		}else{
			if(dp1.at(i+1)!=-1) dp1.at(i) = dp1.at(i+1)+max(cnt.at(i),n-cnt.at(i))*(1LL<<i) ;
			dp2.at(i) = dp2.at(i+1)+cnt.at(i)*(1LL<<i) ;
		}
	}
//	for(int i=10;i>=0;i--) cout << dp1.at(i) << " " << dp2.at(i) << endl ;
//	for(int i=0;i<10;i++) cout << cnt.at(i) << endl ;
	cout << max(dp1.at(0),dp2.at(0)) << endl ;
}
