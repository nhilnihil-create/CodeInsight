#include <iostream>
//#include <iomanip>
#include <string>
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
//void chmin(ll &a,ll b){if(a>b) a = b ;}

int main(){
	string s ; cin >> s ;
	ll n = s.size() ;
	if(s.at(0)=='0'||s.at(n-1)=='1') cout << -1 << endl ;
	else{
		for(int i=1;i<=n/2;i++){
			if(s.at(i-1)!=s.at(n-1-i)){
				cout << -1 << endl ;
				return 0 ;
			}
		}
		s.at(n-1) = '1' ;
		ll pre = n ;
		for(int i=n-1;i>0;i--){
			cout << i << " " << pre << endl ;
			if(s.at(i-1)=='1') pre = i ;
		}
	}
}
