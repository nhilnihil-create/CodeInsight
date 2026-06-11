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
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void mysort(vector<pll> &a){sort(a.begin(),a.end()) ;}
void myrev(vll &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vector<pll> p(n) ;
	for(int i=0;i<n;i++) cin >> p.at(i).first >> p.at(i).second ;
	mysort(p) ;
	ll ans = -1 ;
	for(int i=0;i<n-k+1;i++){
		for(int j=i+k-1;j<n;j++){
			ll w = p.at(j).first - p.at(i).first ;
			ll cnt = 0 ;
			vll subp ;
			ll sky = max(p.at(i).second,p.at(j).second) ;
			ll grn = min(p.at(i).second,p.at(j).second) ;
			for(int l=i;l<=j;l++){
				if(grn<=p.at(l).second&&p.at(l).second<=sky) cnt++ ;
				else subp.push_back(p.at(l).second) ;
			}
			sort(subp.begin(),subp.end()) ;
			myrev(subp) ;
			ll h ;
			if(cnt>=k) h = sky-grn ;
			else{
				ll small = 30000000000 ;
				for(int l=0;l<subp.size()-(k-cnt)+1;l++){
					if(subp.at(l)<grn) small = min(small,sky-subp.at(l+(k-cnt)-1)) ;
					else if(subp.at(l+(k-cnt)-1)>sky) small = min(small,subp.at(l)-grn) ;
					else small = min(small,subp.at(l)-subp.at(l+(k-cnt)-1)) ;
				}
				h = small ;
			}
			if(ans==-1) ans = w*h ;
			else ans = min(ans,w*h) ;
//			cout << w << " " << h << endl ;
		}
	}
	cout << ans << endl ;
}
