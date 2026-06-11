#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
#include <utility>
//#include <set>
#include <map>
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
using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll h,w,d ;
	cin >> h >> w >> d ;
	map<ll,pll> m ;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ll a ; cin >> a ;
			m[a] = {i,j} ;
		}
	}
	vvll sum(d,vll(1,0)) ;
	for(int i=0;i<d;i++){
		for(int j=i+d;j<=h*w;j+=d){
			sum.at(i).emplace_back(sum.at(i).at(sum.at(i).size()-1)+sa(m[j].first,m[j-d].first)+sa(m[j].second,m[j-d].second)) ;
		}
	}
	ll q ; cin >> q ;
	for(int i=0;i<q;i++){
		ll l,r ;
		cin >> l >> r ;
		cout << sum.at(r%d).at(r/d)-sum.at(l%d).at(l/d) << endl ;
	}
}
