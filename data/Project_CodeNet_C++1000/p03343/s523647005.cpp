#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
#include <set>
//#include <map>
#include <queue>
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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 10000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,k,q ;
	cin >> n >> k >> q ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vll b = a ;
	mysort(b) ;
	ll ans = b.at(q-1)-b.at(0) ;
	set<int> s ;
	for(int i=1;i<n;i++){
		if(b.at(i)==b.at(i-1)) continue ;
		vll c(0),sub(0),none(0) ;
		for(int j=0;j<n;j++){
			if(a.at(j)==b.at(i-1)) s.insert(j) ;
		}
		int cnt = 0 ;
		for(int j=0;j<n;j++){
			if(s.count(j)){
				if(cnt<k){
					cnt = 0 ;
					sub = none ;
				}else{
					mysort(sub) ;
					for(int l=0;l<min(q,cnt-k+1);l++){
						c.emplace_back(sub.at(l)) ;
					}
					sub = none ;
					cnt = 0 ;
				}
			}else{
				cnt++ ;
				sub.emplace_back(a.at(j)) ;
			}
		}
		if(sub.size()>0){
			mysort(sub) ;
			for(int j=0;j<min(q,cnt-k+1);j++){
				c.emplace_back(sub.at(j)) ;
			}
		}
		if(c.size()<q) break ;
		mysort(c) ;
		ans = min(ans,c.at(q-1)-c.at(0)) ;
	}
	cout << ans << endl ;
}
