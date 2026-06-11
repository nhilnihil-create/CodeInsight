#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
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
	ll n ; cin >> n ;
	vvll sum(n+1,vll(30,0)) ;
	for(int i=0;i<n;i++){
		ll a ; cin >> a ;
		for(int j=0;j<30;j++){
			sum.at(i+1).at(j) = sum.at(i).at(j)+(a>>j&1) ;
		}
	}
	ll ans = 0 ;
	ll l=0,r=1 ;
	while(r<=n){
		bool ok = true ;
		for(int j=0;j<30;j++){
			if(sum.at(r).at(j)-sum.at(l).at(j)>1) ok = false ;
		}
		if(ok){
			ans += r-l ;
//			cout << l << " " << r << endl ;
//			cout << ans << endl ;
			r++ ;
		}else{
			l++ ;
		}
	}
	cout << ans << endl ;
}
