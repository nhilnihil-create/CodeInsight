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
using vc = vector<char> ;
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
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,a,b,c,d ;
	cin >> n >> a >> b >> c >> d ;
	vc root(n+2,'#') ;
	for(int i=1;i<=n;i++) cin >> root.at(i) ;
	if(c<d){
		ll pos = b ;
		while(pos<d){
			if(root.at(pos+1)=='.') pos++ ;
			else if(root.at(pos+2)=='.') pos += 2 ;
			else break ;
		}
		if(pos!=d){
			cout << "No" << endl ;
			return 0 ;
		}
		pos = a ;
		while(pos<c){
			if(root.at(pos+1)=='.') pos++ ;
			else if(root.at(pos+2)=='.') pos += 2 ;
			else break ;
		}
		if(pos!=c){
			cout << "No" << endl ;
			return 0 ;
		}
		cout << "Yes" << endl ;
	}else{
		bool ok = false ;
		for(int i=b;i<=d;i++){
			if(root.at(i)=='#') continue ;
			if(root.at(i-1)=='.'&&root.at(i+1)=='.') ok = true ;
		}
		if(!ok){
			cout << "No" << endl ;
			return 0 ;
		}
		ll pos = b ;
		while(pos<d){
			if(root.at(pos+1)=='.') pos++ ;
			else if(root.at(pos+2)=='.') pos += 2 ;
			else break ;
		}
		if(pos!=d){
			cout << "No" << endl ;
			return 0 ;
		}
		pos = a ;
		while(pos<c){
			if(root.at(pos+1)=='.') pos++ ;
			else if(root.at(pos+2)=='.') pos += 2 ;
			else break ;
		}
		if(pos!=c){
			cout << "No" << endl ;
			return 0 ;
		}
		cout << "Yes" << endl ;
	}
}
