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
	ll a,b,q ;
	cin >> a >> b >> q ;
	vll s(a),t(b) ;
	for(auto &i:s) cin >> i ;
	for(auto &i:t) cin >> i ;
	sort(all(s)) ;
	sort(all(t)) ;
	for(int i=0;i<q;i++){
		ll x ; cin >> x ;
		ll ans = INF ;
//		神社→寺、右右、右左、左右、左左
		auto itr = lower_bound(all(s),x) ;
		if(itr!=s.end()){
			auto tmp = lower_bound(all(t),*itr) ;
			if(tmp!=t.end()){
				ans = min(ans,*tmp-x) ;
			}
			if(tmp!=t.begin()){
				tmp-- ;
				ans = min(ans,*itr-x+*itr-*tmp) ;
			}
		}
		if(itr!=s.begin()){
			itr-- ;
			auto tmp = lower_bound(all(t),*itr) ;
			if(tmp!=t.end()){
				ans = min(ans,x-*itr+*tmp-*itr) ;
			}
			if(tmp!=t.begin()){
				tmp-- ;
				ans = min(ans,x-*tmp) ;
			}
		}
//		寺→神社、右右、右左、左右、左左
		itr = lower_bound(all(t),x) ;
		if(itr!=t.end()){
			auto tmp = lower_bound(all(s),*itr) ;
			if(tmp!=s.end()){
				ans = min(ans,*tmp-x) ;
			}
			if(tmp!=s.begin()){
				tmp-- ;
				ans = min(ans,*itr-x+*itr-*tmp) ;
			}
		}
		if(itr!=t.begin()){
			itr-- ;
			auto tmp = lower_bound(all(s),*itr) ;
			if(tmp!=s.end()){
				ans = min(ans,x-*itr+*tmp-*itr) ;
			}
			if(tmp!=s.begin()){
				tmp-- ;
				ans = min(ans,x-*tmp) ;
			}
		}
		cout << ans << endl ;
	}
}
