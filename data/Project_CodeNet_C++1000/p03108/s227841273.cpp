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
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
//void chmin(ll &a,ll b){if(a>b) a = b ;}


const int MAX = 10000000 ;
// UFTクラスを宣言するときはグローバル変数か、staticをつけて静的変数にすること
class UFT{
public :
	int par[MAX] ;
	int rank[MAX] ;
	int size[MAX] ;
	bool root[MAX] ;
	int tree ;

	void init(int n){
		for(int i=0;i<n;i++){
			par[i] = i ;
			rank[i] = 0 ;
			size[i] = 1 ;
			root[i] = true ;
		}
		tree = n ;
	}

	int find(int x){
		if(par[x]==x) return x ;
		return par[x] = find(par[x]) ;
	}

	void unite(int x,int y){
		x = find(x) ;
		y = find(y) ;
		if(x==y){
			if(root[x]){
				root[x] = false ;
				tree-- ;
			}
			return ;
		}
		if(rank[x]<rank[y]){
			par[x] = y ;
			size[y] += size[x] ;
			if(root[x]){
				root[x] = false ;
				tree-- ;
			}
		}else{
			par[y] = x ;
			size[x] += size[y] ;
			if(rank[x]==rank[y]) rank[x]++ ;
			if(root[y]){
				root[y] = false ;
				tree-- ;
			}
		}
	}

	bool same(int x,int y){
		return find(x)==find(y) ;
	}
};

int main(){
	ll n,m ;
	cin >> n >> m ;
	vector<pll> e(m) ;
	for(int i=0;i<m;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ;
		b-- ;
		e.at(i).first = a ;
		e.at(i).second = b ;
	}
	reverse(all(e)) ;
	vll ans(m+1,0) ;
	ans.at(0) = n*(n-1)/2 ;
	static UFT uft ;
	uft.init(n) ;
	for(int i=0;i<m;i++){
		ll sub = 0 ;
		if(!uft.same(e.at(i).first,e.at(i).second)){
			sub = uft.size[uft.par[e.at(i).first]]*uft.size[uft.par[e.at(i).second]] ;
//			cout << i << " " << uft.size[e.at(i).first] << " " << uft.size[e.at(i).second] << endl ;
			uft.unite(e.at(i).first,e.at(i).second) ;
		}
		ans.at(i+1) = ans.at(i)-sub ;
	}
	reverse(all(ans)) ;
	for(int i=1;i<=m;i++) cout << ans.at(i) << endl ;
}
