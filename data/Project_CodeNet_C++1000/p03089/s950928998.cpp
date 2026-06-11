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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n ; cin >> n ;
	vll b(n) ;
	for(auto &i:b) cin >> i ;
	vll ans ;
	for(int i=0;i<n;i++){
		ll pos = -1 ;
		ll zero = 0 ;
		for(int j=0;j<n;j++){
			if(j+1-zero==b.at(j)) pos = j ;
			else if(b.at(j)==0) zero++ ;
		}
		if(pos==-1){
			cout << -1 << endl ;
			return 0 ;
		}
		ans.push_back(b.at(pos)) ;
		b.at(pos) = 0 ;
	}
	myrev(ans) ;
	for(int i=0;i<n;i++) cout << ans.at(i) << endl ;
}

