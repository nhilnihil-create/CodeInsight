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
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vll &a){sort(a.begin(),a.end()) ;}
//void myrev(vll &a){reverse(a.begin(),a.end()) ;}

int main(){
	string s ; cin >> s ;
	ll n = s.size() ;
	vector<string> vec ;
	string t = "" ;
	for(int i=0;i<n;i++){
		if(s.at(i)=='A') t += 'A' ;
		else if(s.at(i)=='C'){
			vec.push_back(t) ;
			t = "" ;
		}else{
			if(i==n-1||s.at(i+1)!='C'){
				vec.push_back(t) ;
				t = "" ;
			}else{
				t += 'D' ;
				i++ ;
			}
		}
	}
	vec.push_back(t) ;
	ll ans = 0 ;
	for(int i=0;i<vec.size();i++){
		ll cnt = 0 ;
		for(int j=0;j<vec.at(i).size();j++){
			if(vec.at(i).at(j)=='A') cnt++ ;
			else ans += cnt ;
		}
	}
	cout << ans << endl ;
}
