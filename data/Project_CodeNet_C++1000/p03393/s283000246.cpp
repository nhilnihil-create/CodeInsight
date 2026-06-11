#include <iostream>
//#include <iomanip>
#include <string>
//#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
//using ll = long long ;
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

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
void myrev(string &a){reverse(a.begin(),a.end()) ;}

int main(){
	string s ; cin >> s ;
	int n = s.size() ;
	if(n!=26){
		for(char c='a';c<='z';c++){
			bool ok = true ;
			for(int i=0;i<n;i++){
				if(s.at(i)==c) ok = false ;
			}
			if(ok){
				cout << s << c << endl ;
				return 0 ;
			}
		}
	}else{
		string az = "abcdefghijklmnopqrstuvwxyz" ;
		myrev(az) ;
		if(s==az) cout << -1 << endl ;
		else{
			for(int i=n-2;i>=0;i--){
				for(int j=n-1;j>i;j--){
					if(s.at(i)<s.at(j)){
						for(int k=0;k<i;k++) cout << s.at(k) ;
						cout << s.at(j) << endl ;
						return 0 ;
					}
				}
			}
		}
	}
}
