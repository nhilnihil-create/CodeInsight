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
	ll n,m,q ;
	cin >> n >> m >> q ;
	vvll sum(n+1,vll(n+1,0)) ;
	for(int i=0;i<m;i++){
		ll a,b ;
		cin >> a >> b ;
		sum.at(1).at(n)++ ;
		if(b!=0)sum.at(1).at(b-1)-- ;
		if(a!=n) sum.at(a+1).at(n)-- ;
		if(a!=n&&b!=0) sum.at(a+1).at(b-1)++ ;
	}
//	cout << -1 << endl ;
	for(int i=0;i<=n;i++) for(int j=n-1;j>=0;j--) sum.at(i).at(j) += sum.at(i).at(j+1) ;
	for(int j=0;j<=n;j++) for(int i=1;i<=n;i++) sum.at(i).at(j) += sum.at(i-1).at(j) ;
	for(int i=0;i<q;i++){
		ll a,b ;
		cin >> a >> b ;
		cout << sum.at(a).at(b) << endl ;
	}
}
