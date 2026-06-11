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
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	ll mx = -INF ;
	ll mn = INF ;
	ll px,pn ;
	for(int i=0;i<n;i++){
		cin >> a.at(i) ;
		if(mx<a.at(i)) mx=a.at(i),px=i+1 ;
		if(mn>a.at(i)) mn=a.at(i),pn=i+1 ;
	}
	if(mn>=0){
		cout << n-1 << endl ;
		for(int i=2;i<=n;i++) cout << i-1 << " " << i << endl ;
		return 0 ;
	}
	if(mx<=0){
		cout << n-1 << endl ;
		for(int i=n-1;i>=1;i--)	cout << i+1 << " " << i << endl ;
		return 0 ;
	}
	if(mx>=abs(mn)){
		ll cnt = 0 ;
		for(int i=0;i<n;i++) if(a.at(i)<0) cnt++ ;
		cout << cnt+n-1 << endl ;
		for(int i=0;i<n;i++) if(a.at(i)<0) cout << px << " " << i+1 << endl ;
		for(int i=2;i<=n;i++) cout << i-1 << " " << i << endl ;
		return 0 ;
	}
	if(mx<=abs(mn)){
		ll cnt = 0 ;
		for(int i=0;i<n;i++) if(a.at(i)>0) cnt++ ;
		cout << cnt+n-1 << endl ;
		for(int i=0;i<n;i++) if(a.at(i)>0) cout << pn << " " << i+1 << endl ;
		for(int i=n-1;i>=1;i--) cout << i+1 << " " << i << endl ;
		return 0 ;
	}
}
