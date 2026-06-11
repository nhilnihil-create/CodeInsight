#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
#include <set>
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
#define all(v) v.begin(),v.end()
ll mod = 998244353 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

vll fac(2,1),inv(2,1),finv(2,1) ;

void nCr_set(ll n){
	for(int i=2;i<=n;i++){
		fac.emplace_back(fac.at(fac.size()-1)*i%mod) ;
		inv.emplace_back(mod-inv.at(mod%i)*(mod/i)%mod) ;
		finv.emplace_back(finv.at(finv.size()-1)*inv.at(i)%mod) ;
	}
}

ll nCr(ll n,ll r){
	if(n<0||r<0||n<r) return 0 ;
	if(n==r||r==0) return 1 ;
	return fac.at(n)*finv.at(n-r)%mod*finv.at(r)%mod ;
}

ll nHr(ll n,ll r) {
	return nCr(n+r-1,n-1) ;
}

int main(){
	ll n,a,b,k ;
	cin >> n >> a >> b >> k ;
	nCr_set(n) ;
	ll ans = 0 ;
	for(int i=0;i<=n;i++){
		if((k-a*i)%b!=0) continue ;
		ans += nCr(n,i)*nCr(n,(k-a*i)/b)%mod ;
		ans %= mod ;
	}
	cout << ans << endl ;
}
