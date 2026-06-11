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
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll m,k ;
	cin >> m >> k ;
	if((1<<m)-1<k){
		cout << -1 << endl ;
		return 0 ;
	}
	if(k==0){
		for(int i=0;i<(1<<m);i++) cout << i << " " << i << (i+1==(1<<m)?"\n":" ") ;
		return 0 ;
	}
	vll ans(1<<(m+1),0) ;
	ans.at(0) = k ;
	for(int i=1;i<(1<<m);i++){
		ans.at(i) = i-1+(i-1>=k) ;
	}
	ans.at(1<<m) = k ;
	for(int i=0;i<(1<<m)-1;i++){
		ans.at((1<<(m+1))-1-i) = i+(i>=k) ;
	}
	ll sum = 0 ;
	for(int i=1;i<(1<<m);i++) sum ^= ans.at(i) ;
	if(sum==k) for(int i=0;i<(1<<(m+1));i++) cout << ans.at(i) << (i+1==(1<<(m+1))?"\n":" ") ;
	else cout << -1 << endl ;
//	for(auto i:ans) cout << i << " " ; cout << endl ;
}
