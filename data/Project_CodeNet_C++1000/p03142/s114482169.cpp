#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <deque>
//#include <bitset>
#include <math.h>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1e10 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

void DFS(vvll &g,vll &par,vll &cnt,int p,int pre){
	par[p] = pre ;
	for(int i=0;i<g[p].size();i++) cnt[g[p][i]]-- ;
	for(int i=0;i<g[p].size();i++) if(cnt[g[p][i]]==0&&par[g[p][i]]==-1) DFS(g,par,cnt,g[p][i],p+1) ;
}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vvll g(n) ;
	vll cnt(n,0) ;
	for(int i=1;i<n+m;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g[a].push_back(b) ;
		cnt[b]++ ;
	}
	vll par(n,-1) ;
	for(int i=0;i<n;i++){
		if(cnt[i]==0){
			DFS(g,par,cnt,i,0) ;
			break ;
		}
	}
	for(auto i:par) cout << i << endl ;
}
