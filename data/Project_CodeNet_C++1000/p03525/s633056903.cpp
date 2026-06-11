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
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 998244353 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
//ld dis(ll a,ll b,ll c,ll d){return sqrt((a-c)*(a-c)+(b-d)*(b-d)) ;}

int main(){
	ll n ; cin >> n ;
	vll cnt(13,0) ;
	cnt.at(0)++ ;
	for(int i=0;i<n;i++){
		ll a ; cin >> a ;
		cnt.at(a)++ ;
	}
	vll t,b ;
	for(int i=0;i<13;i++){
		if(cnt.at(i)==0) continue ;
		if(cnt.at(i)==1){
			if(i==0||i==12){
				t.emplace_back(i) ;
			}else{
				b.emplace_back(i) ;
			}
		}
		if(cnt.at(i)==2){
			if(i==0||i==12){
				cout << 0 << endl ;
				return 0 ;
			}
			t.emplace_back(i) ;
			t.emplace_back(24-i) ;
		}
		if(cnt.at(i)>=3){
			cout << 0 << endl ;
			return 0 ;
		}
	}
	ll ans = 0 ;
	for(int i=0;i<(1<<b.size());i++){
		bitset<15> bit(i) ;
		vll c = t ;
		for(int j=0;j<b.size();j++){
			if(bit[j]) c.emplace_back(b.at(j)) ;
			else c.emplace_back(24-b.at(j)) ;
		}
		sort(all(c)) ;
		c.emplace_back(0) ;
		ll d = 12 ;
		for(int j=0;j<c.size()-1;j++) d = min(d,min(sa(c.at(j),c.at(j+1)),24-sa(c.at(j),c.at(j+1)))) ;
		ans = max(ans,d) ;
	}
	cout << ans << endl ;
}
