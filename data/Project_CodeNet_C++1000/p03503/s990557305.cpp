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
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vvll time(n,vll(10)) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			cin >> time.at(i).at(j) ;
		}
	}
	vvll p(n,vll(11)) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++){
			cin >> p.at(i).at(j) ;
		}
	}
	ll ans = -10000000000000 ;
	for(int i=1;i<(1<<10);i++){
		bitset<15> bit(i) ;
		ll sub = 0 ;
		for(int j=0;j<n;j++){
			ll cnt = 0 ;
			for(int k=0;k<10;k++){
				cnt += bit[k]&&time.at(j).at(k) ;
			}
			sub += p.at(j).at(cnt) ;
		}
		ans = max(ans,sub) ;
	}
	cout << ans << endl ;
}
