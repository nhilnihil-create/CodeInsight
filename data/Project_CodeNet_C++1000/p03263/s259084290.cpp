#include <iostream>
//#include <iomanip>
#include <string>
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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

vll a,b,c,d ;

void ins(int i,int j,int k,int l){
	a.emplace_back(i) ;
	b.emplace_back(j) ;
	c.emplace_back(k) ;
	d.emplace_back(l) ;
}

int main(){
	ll h,w ;
	cin >> h >> w ;
	vvll g(h+2,vll(w+2,0)) ;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin >> g.at(i).at(j) ;
	for(int i=1;i<=h;i++){
		if(i&1){
			for(int j=1;j<w;j++){
				if(g.at(i).at(j)&1){
					ins(i,j,i,j+1) ;
					g.at(i).at(j+1)++ ;
				}
			}
			if(i!=h&&g.at(i).at(w)&1){
				ins(i,w,i+1,w) ;
				g.at(i+1).at(w)++ ;
			}
		}else{
			for(int j=w;j>1;j--){
				if(g.at(i).at(j)&1){
					ins(i,j,i,j-1) ;
					g.at(i).at(j-1)++ ;
				}
			}
			if(i!=h&&g.at(i).at(1)&1){
				ins(i,1,i+1,1) ;
				g.at(i+1).at(1)++ ;
			}
		}
	}
	cout << a.size() << endl ;
	for(int i=0;i<a.size();i++) cout << a.at(i) << " " << b.at(i) << " " << c.at(i) << " " << d.at(i) << endl ;
}
