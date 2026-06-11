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
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vll a(n),b(n),c(n) ;
	for(int i=0;i<n;i++) cin >> a.at(i) >> b.at(i) >> c.at(i) ;
	ll ans = -INF ;
	vll sub(n) ;
	ll cnt1,cnt2 ;
	for(int i=0;i<n;i++) sub.at(i) = a.at(i)+b.at(i)+c.at(i) ;
	sort(all(sub)) ;
	cnt1 = 0 ; cnt2 = 0 ;
	for(int i=0;i<m;i++){
		cnt1 -= sub.at(i) ;
		cnt2 += sub.at(n-1-i) ;
	}
	ans = max(ans,max(cnt1,cnt2)) ;
	for(int i=0;i<n;i++) sub.at(i) = a.at(i)+b.at(i)-c.at(i) ;
	sort(all(sub)) ;
	cnt1 = 0 ; cnt2 = 0 ;
	for(int i=0;i<m;i++){
		cnt1 -= sub.at(i) ;
		cnt2 += sub.at(n-1-i) ;
	}
	ans = max(ans,max(cnt1,cnt2)) ;
	for(int i=0;i<n;i++) sub.at(i) = a.at(i)-b.at(i)+c.at(i) ;
	sort(all(sub)) ;
	cnt1 = 0 ; cnt2 = 0 ;
	for(int i=0;i<m;i++){
		cnt1 -= sub.at(i) ;
		cnt2 += sub.at(n-1-i) ;
	}
	ans = max(ans,max(cnt1,cnt2)) ;
	for(int i=0;i<n;i++) sub.at(i) = -a.at(i)+b.at(i)+c.at(i) ;
	sort(all(sub)) ;
	cnt1 = 0 ; cnt2 = 0 ;
	for(int i=0;i<m;i++){
		cnt1 -= sub.at(i) ;
		cnt2 += sub.at(n-1-i) ;
	}
	ans = max(ans,max(cnt1,cnt2)) ;
	cout << ans << endl ;
}
