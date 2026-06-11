#include <iostream>
//#include <iomanip>
#include <string>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
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
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int Dsum(int a){
	string s = to_string(a) ;
	int res = 0 ;
	for(int i=0;i<s.size();i++) res += s.at(i)-'0' ;
	return res ;
}

int main(){
	int n ; cin >> n ;
	int ans = 10000 ;
	for(int i=1;i<n;i++){
		int a = i ;
		int b = n-i ;
		int sum = Dsum(a)+Dsum(b) ;
		if(ans>sum) ans = sum ;
	}
	cout << ans << endl ;
}
