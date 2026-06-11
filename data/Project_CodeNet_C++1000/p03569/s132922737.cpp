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
	string s ; cin >> s ;
	vll x ;
	string sub ;
	ll cnt = 0 ;
	for(int i=0;i<s.size();i++){
		if(s.at(i)=='x') cnt++ ;
		else{
			sub += s.at(i) ;
			x.emplace_back(cnt) ;
			cnt = 0 ;
		}
	}
	x.emplace_back(cnt) ;
	string ch = sub ;
	reverse(ch.begin(),ch.end()) ;
	if(ch!=sub) cout << -1 << endl ;
	else{
		ll ans = 0 ;
		for(int i=0;i<x.size()/2;i++){
			ans += abs(x.at(i)-x.at(x.size()-1-i)) ;
		}
		cout << ans << endl ;
	}
}
