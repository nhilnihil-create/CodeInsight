#include <iostream>
//#include <iomanip>
#include <string>
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
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

void solve(){
	ll a,b,c,d ;
	cin >> a >> b >> c >> d ;
	if(d<b||a<b){
		yorn(0) ;
		return  ;
	}
	if(c>=b-1){
		yorn(1) ;
		return  ;
	}
	if(d%b==0){
		a %= b ;
		yorn(a<=c) ;
		return  ;
	}
	ll g = gcd(b,d) ;
	if(b-1-c>=g){
		yorn(0) ;
		return ;
	}
	g = d%b ;
	ll s = a%b ;
	ll t = (b-1)%g ;
	ll u = (c+1)%g ;
	if(t>=u) yorn(!(u<=s&&s<=t)) ;
	else yorn(t<s&&s<u) ;
}

int main(){
	ll t ; cin >> t ;
	while(t--){
		solve() ;
	}
}
