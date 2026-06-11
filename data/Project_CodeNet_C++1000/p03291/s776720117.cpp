#include <iostream>
//#include <iomanip>
#include <string>
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
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

ll modpow(ll a,ll b){
	if(b==0) return 1 ;
	if(b<0) return 0 ;
	ll res = 1 ;
	while(b>0){
		if(b&1) res = res*a%mod ;
		b >>= 1 ;
		a = a*a%mod ;
	}
	return res ;
}

int main(){
	string s ; cin >> s ;
	ll n = s.size() ;
	vll q(n+1,0),b(n+1,0),c(n+1,0) ;
	for(int i=n-1;i>=0;i--){
		q.at(i) += q.at(i+1)+(s.at(i)=='?') ;
		b.at(i) += b.at(i+1)+(s.at(i)=='B') ;
		c.at(i) += c.at(i+1)+(s.at(i)=='C') ;
	}
	vll bc(n+1,0),bq(n+1,0),qc(n+1,0),qq(n+1,0) ;
	for(int i=n-1;i>=0;i--){
		bc.at(i) += bc.at(i+1) ;
		bq.at(i) += bq.at(i+1) ;
		qc.at(i) += qc.at(i+1) ;
		qq.at(i) += qq.at(i+1) ;
		if(s.at(i)=='?'){
			qc.at(i) += c.at(i+1) ;
			qq.at(i) += q.at(i+1) ;
		}
		if(s.at(i)=='B'){
			bc.at(i) += c.at(i+1) ;
			bq.at(i) += q.at(i+1) ;
		}
	}
	ll ans = 0 ;
	for(int i=0;i<n;i++){
//		cout << ans << endl ;
		ll h = 0 ;
		if(s.at(i)=='A'||s.at(i)=='?'){
			if(s.at(i)=='?') h = 1 ;
			ans += bc.at(i+1)*modpow(3,q.at(0)-h)%mod ;
			ans += bq.at(i+1)*modpow(3,q.at(0)-1-h)%mod ;
			ans += qc.at(i+1)*modpow(3,q.at(0)-1-h)%mod ;
			ans += qq.at(i+1)*modpow(3,q.at(0)-2-h)%mod ;
			ans %= mod ;
		}
	}
	cout << ans << endl ;
//	for(auto i:bc) cout << i << " " ; cout << endl ;
//	for(auto i:bq) cout << i << " " ; cout << endl ;
//	for(auto i:qc) cout << i << " " ; cout << endl ;
//	for(auto i:qq) cout << i << " " ; cout << endl ;
//	for(auto i:q)  cout << i << " " ; cout << endl ;
}
