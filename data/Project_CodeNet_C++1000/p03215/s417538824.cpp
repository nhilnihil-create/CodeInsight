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
using vb = vector<bool> ;
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
//void chmin(ll &a,ll b){if(a>b) a = b ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll sum(n+1,0) ;
	for(int i=1;i<=n;i++){
		ll a ; cin >> a ;
		sum.at(i) = sum.at(i-1)+a ;
	}
	vector<bitset<40>> bit ;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bit.emplace_back(sum.at(j)-sum.at(i-1)) ;
		}
	}
	vb ok(bit.size(),true) ;
	ll ans = 0 ;
	for(int i=39;i>=0;i--){
		ll cnt = 0 ;
		for(int j=0;j<bit.size();j++){
			if(ok.at(j)&&bit.at(j)[i]) cnt++ ;
		}
		if(cnt>=k){
			ans += (1LL<<i) ;
			for(int j=0;j<bit.size();j++){
				if(ok.at(j)&&!bit.at(j)[i]) ok.at(j) = false ;
			}
		}
	}
	cout << ans << endl ;
}
