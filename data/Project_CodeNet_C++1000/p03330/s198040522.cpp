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
using vvll = vector<vll> ;
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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,c ;
	cin >> n >> c ;
	vvll d(c,vll(c)) ;
	for(int i=0;i<c;i++) for(int j=0;j<c;j++) cin >> d.at(i).at(j) ;
	vvll s(n,vll(n)) ;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> s.at(i).at(j) ;
	vvll cnt(c,vll(3,0)) ;
//	cout << 1 << endl ;
	for(int i=0;i<c;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
//				cout << i << " " << j << " " << k << endl ;
				cnt.at(i).at((j+k)%3) += d.at(s.at(j).at(k)-1).at(i) ;
			}
		}
	}
//	cout << 2 << endl ;
	ll ans = INF ;
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<c;k++){
				if(i!=j&&j!=k&&k!=i){
					ans = min(ans,cnt.at(i).at(0)+cnt.at(j).at(1)+cnt.at(k).at(2)) ;
				}
			}
		}
	}
	cout << ans << endl ;
}
