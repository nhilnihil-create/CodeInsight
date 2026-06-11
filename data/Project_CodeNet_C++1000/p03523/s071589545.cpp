#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
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

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	string s ; cin >> s ;
	string sub = "KIHBR" ;
	int pos = 0 ;
	for(int i=0;i<s.size();i++){
		if(pos!=5&&s.at(i)==sub.at(pos)) pos++ ;
	}
	if(pos!=5){
		cout << "NO" << endl ;
		return 0 ;
	}
	sub = "AKIHABARA" ;
	pos = 0 ;
	for(int i=0;i<9;i++){
		if(sub.at(i)==s.at(pos)) pos++ ;
		if(pos==s.size()){
			cout << "YES" << endl ;
			return 0 ;
		}
	}
	cout << "NO" << endl ;
}
