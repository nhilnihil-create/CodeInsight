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
#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n ; cin >> n ;
	vvll a(n,vll(10)) ;
	vvll b(n,vll(11)) ;
	for(int i=0;i<n;i++) for(int j=0;j<10;j++) cin >> a.at(i).at(j) ;
	for(int i=0;i<n;i++) for(int j=0;j<11;j++) cin >> b.at(i).at(j) ;
	ll ans = -100000000000 ;
	for(int i=1;i<(1<<10);i++){
		bitset<15> bit(i) ;
		ll sub = 0 ;
		for(int j=0;j<n;j++){
			ll cnt = 0 ;
			for(int k=0;k<10;k++) cnt += (bit[k]&&a.at(j).at(k)) ;
			sub += b.at(j).at(cnt) ;
		}
		if(ans<sub) ans = sub ;
	}
	cout << ans << endl ;
}
