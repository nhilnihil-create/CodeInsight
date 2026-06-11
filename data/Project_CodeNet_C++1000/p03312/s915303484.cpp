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
	for(auto &i:a) cin >> i ;
	vll sum(n+1,0) ;
	for(int i=0;i<n;i++) sum.at(i+1) = sum.at(i)+a.at(i) ;
	ll ans = INF ;
	for(int i=2;i<=n-2;i++){
		ll s1,s2,s3,s4 ;
		ll l1=0,r1=i,m1 ;
		while(l1+1<r1){
			m1 = (l1+r1)/2 ;
			if(2*sum.at(m1)<sum.at(i)) l1 = m1 ;
			else r1 = m1 ;
		}
		if(l1==0){
			s1 = sum.at(1) ;
			s2 = sum.at(i)-sum.at(1) ;
		}else if(r1==i){
			s1 = sum.at(l1) ;
			s2 = sum.at(i)-sum.at(l1) ;
		}else if(sum.at(i)-2*sum.at(l1)>2*sum.at(r1)-sum.at(i)){
			s1 = sum.at(r1) ;
			s2 = sum.at(i)-sum.at(r1) ;
		}else{
			s1 = sum.at(l1) ;
			s2 = sum.at(i)-sum.at(l1) ;
		}
		ll l2=i,r2=n,m2 ;
		while(l2+1<r2){
			m2 = (l2+r2)/2 ;
			if(2*(sum.at(m2)-sum.at(i))<sum.at(n)-sum.at(i)) l2 = m2 ;
			else r2 = m2 ;
		}
		if(l2==i){
			s3 = sum.at(i+1)-sum.at(i) ;
			s4 = sum.at(n)-sum.at(i+1) ;
		}else if(r1==n){
			s3 = sum.at(l2)-sum.at(i) ;
			s4 = sum.at(n)-sum.at(l2) ;
		}else if(sum.at(n)-sum.at(i)-2*(sum.at(l2)-sum.at(i))>2*(sum.at(r2)-sum.at(i))-sum.at(n)+sum.at(i)){
			s3 = sum.at(r2)-sum.at(i) ;
			s4 = sum.at(n)-sum.at(r2) ;
		}else{
			s3 = sum.at(l2)-sum.at(i) ;
			s4 = sum.at(n)-sum.at(l2) ;
		}
		ans = min(ans,max(max(s1,s2),max(s3,s4))-min(min(s1,s2),min(s3,s4))) ;
	}
	cout << ans << endl ;
}
