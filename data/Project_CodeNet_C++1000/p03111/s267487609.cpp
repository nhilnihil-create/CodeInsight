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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

ll n,A,B,C ;
vll l ;

ll DFS(ll a,ll b,ll c,ll cnt){
	if(cnt==n) return (a*b*c==0?INF:abs(a-A)+abs(b-B)+abs(c-C)-30) ;
	ll r1 = DFS(a,b,c,cnt+1) ;
	ll r2 = DFS(a+l.at(cnt),b,c,cnt+1)+10 ;
	ll r3 = DFS(a,b+l.at(cnt),c,cnt+1)+10 ;
	ll r4 = DFS(a,b,c+l.at(cnt),cnt+1)+10 ;
	return min(min(r1,r2),min(r3,r4)) ;
}

int main(){
	cin >> n >> A >> B >> C ;
	l.resize(n) ;
	for(auto &i:l) cin >> i ;
	cout << DFS(0,0,0,0) << endl ;
}
