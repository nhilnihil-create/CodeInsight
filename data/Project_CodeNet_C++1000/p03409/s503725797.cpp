#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
#include <utility>
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
using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vector<pll> a(n),b(n) ;
	for(int i=0;i<n;i++) cin >> a.at(i).first >> a.at(i).second ;
	for(int i=0;i<n;i++) cin >> b.at(i).first >> b.at(i).second ;
	sort(all(a)) ;
	sort(all(b)) ;
	ll ans = 0 ;
	vb used(n,true) ;
	for(int i=0;i<n;i++){
		ll pos = -1 ;
		for(int j=0;j<n;j++){
			if(a.at(j).first>=b.at(i).first) break ;
			if(used.at(j)&&a.at(j).second<b.at(i).second){
				if(pos==-1) pos = j ;
				else if(a.at(pos).second<=a.at(j).second) pos = j ;
			}
		}
		if(pos!=-1){
			ans++ ;
			used.at(pos) = false ;
		}
	}
	cout << ans << endl ;
}
