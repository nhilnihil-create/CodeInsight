#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <tuple>
#include <math.h>
#include <set>
#include <map>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end() 
const ll INF = 1e18 ;
const ll mod = 1e9+7 ;
const double pie = acos(-1); 
vll dx4 = {-1,0,1,0} ;
vll dy4 = {0,-1,0,1} ;
vll dx8 = {-1,0,1,1,1,0,-1,-1} ;
vll dy8 = {-1,-1,-1,0,1,1,1,0} ; 

void fix_cout(){cout << fixed << setprecision(20) ; }
ll gcd(ll a,ll b){if(b==0) return a ; return gcd(b,a%b) ; }
ll lcm(ll a,ll b){return a/gcd(a,b)*b ; }
void chmax(ll &a,ll b){if(a<b) a = b ; }
void chmin(ll &a,ll b){if(a>b) a = b ; }

int main(){
	ll n ; cin >> n ;
	vvll g(n,vll(0)) ;
	for(int i=0;i<n-1;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g.at(a).push_back(b) ;
		g.at(b).push_back(a) ;
	}
	vll ans(n,-1) ;
	vll c(n) ;
	for(auto &i:c) cin >> i ;
	sort(all(c)) ;
	reverse(all(c)) ;
	queue<ll> q ;
	ans.at(0) = c.at(0) ;
	q.push(0) ;
	ll pos = 0 ;
	while(!q.empty()){
		ll p = q.front() ;
		q.pop() ;
		ans.at(p) = c.at(pos) ;
		pos++ ;
		for(int i=0;i<g.at(p).size();i++){
			if(ans.at(g.at(p).at(i))==-1) q.push(g.at(p).at(i)) ;
		}
	}
	ll sum = 0 ;
	for(int i=1;i<n;i++) sum += c.at(i) ;
	cout << sum << endl ;
	for(int i=0;i<n;i++) cout << ans.at(i) << (i==n-1?"\n":" ") ;
}