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
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//ll INF = 100000000 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	string s ; cin >> s ;
	char c = s.at(0) ;
	vll one,zero ;
	if(c=='0') one.push_back(0) ;
	ll cnt = 0 ;
	for(int i=0;i<n;i++){
		if(c=='1'){
			if(s.at(i)=='1') cnt++ ;
			else{
				one.push_back(cnt) ;
				cnt = 1 ;
				c = '0' ;
			}
		}else{
			if(s.at(i)=='0') cnt++ ;
			else{
				zero.push_back(cnt) ;
				cnt = 1 ;
				c = '1' ;
			}
		}
	}
	if(c=='1') one.push_back(cnt) ;
	else{
		zero.push_back(cnt) ;
		one.push_back(0) ;
	}
	if(zero.size()<=k) cout << n << endl ;
	else{
		ll ans = 0 ;
		vll sum_zero(zero.size()+1,0) ;
		for(int i=1;i<=zero.size();i++) sum_zero.at(i) = sum_zero.at(i-1)+zero.at(i-1) ;
		vll sum_one(one.size()+1,0) ;
		for(int i=1;i<=one.size();i++) sum_one.at(i) = sum_one.at(i-1)+one.at(i-1) ;
		for(int i=0;i<zero.size()-k+1;i++){
			ll sub = sum_zero.at(i+k)-sum_zero.at(i)+sum_one.at(i+k+1)-sum_one.at(i) ;
			if(ans<sub) ans = sub ;
		}
		cout << ans << endl ;
	}
}
