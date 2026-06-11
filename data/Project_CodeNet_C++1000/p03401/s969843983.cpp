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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n ; cin >> n ;
	vll a(n+2,0) ;
	for(int i=1;i<=n;i++) cin >> a.at(i) ;
	ll def = 0 ;
	for(int i=0;i<n+1;i++){
		def += sa(a.at(i),a.at(i+1)) ;
	}
	for(int i=1;i<=n;i++){
		if((a.at(i-1)<=a.at(i)&&a.at(i)<=a.at(i+1))||(a.at(i-1)>=a.at(i)&&a.at(i)>=a.at(i+1))) cout << def << endl ;
		else{
			ll d = sa(a.at(i-1),a.at(i))+sa(a.at(i),a.at(i+1))-sa(a.at(i-1),a.at(i+1)) ;
			cout << def-d << endl ;
		}
	}
}
