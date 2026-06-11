#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
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
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
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
//void fix_cout(){cout << fixed << setprecision(20) ;}

const int MAX = 10000000 ;
// UFTクラスを宣言するときはグローバル変数か、staticをつけて静的変数にすること
class UFT{
public :
	int par[MAX] ;
	int rank[MAX] ;
	int size[MAX] ;
	bool root[MAX] ;
	int graph ;
	int tree ;

	void init(int n){
		for(int i=0;i<n;i++){
			par[i] = i ;
			rank[i] = 0 ;
			size[i] = 1 ;
			root[i] = true ;
		}
		tree = n ;
		graph = n ;
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
			graph-- ;
			if(root[x]){
				root[x] = false ;
				tree-- ;
			}
		}else{
			par[y] = x ;
			size[x] += size[y] ;
			if(rank[x]==rank[y]) rank[x]++ ;
			graph-- ;
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
	static UFT uft ;
	uft.init(n) ;
	for(int i=0;i<m;i++){
		ll a,b,c ;
		cin >> a >> b >> c ;
		a-- ; b-- ;
		uft.unite(a,b) ;
	}
	cout << uft.graph << endl ;
}
