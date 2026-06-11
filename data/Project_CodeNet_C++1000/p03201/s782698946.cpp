#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
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
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
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
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	sort(all(a)) ;
	reverse(all(a)) ;
	map<ll,ll> m ;
	for(int i=0;i<n;i++) m[a.at(i)]++ ;
	ll ans = 0 ;
	for(int i=0;i<n;i++){
		for(int j=31;j>=0;j--){
			ll d = (1ll<<j)-a.at(i) ;
			if(m[a.at(i)]>0&&m.count(d)&&m[d]>(d==a.at(i)?1:0)){
				ans++ ;
				m[a.at(i)]-- ;
				m[d]-- ;
			}
		}
	}
	cout << ans << endl ;
}
