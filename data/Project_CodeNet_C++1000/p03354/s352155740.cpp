// "header" {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <tuple>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int> 
#define int int64_t
#define Fixed fixed << setprecision(10)
#define moke_pair make_pair
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000007;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class T,class U> using umap = unordered_map<T,U>;
template <class T> inline int getint(T s){ 
    int n;
    cout << s;
    cin >> n;
    return n;
}

inline int64_t updiv(int64_t n,int64_t d){
    return ((n + d -1) / d);
}
/*
inline double Sqrt( const double &x) 
{
	double         xHalf = 0.5 * x;
	int64_t  tmp   = 0x5FE6EB50C7B537AAl - ( *(int64_t*)&x >> 1);
	double         xRes  = * (double*)&tmp;

	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	return xRes * x;
}
*/
// }}}

//UnionFind{{{
struct UnionFind {
    vector < int > par;
    vector < int > siz;

    UnionFind(int n): par(n), siz(n, 1) { //初期化
        for(int i = 0; i < n; i++) par[i] = i;
    }
	
    int root(int x){ //根の更新＋判定
        if(par[x] == x) return x;
		else return par[x] = root(par[x]);
    }

    int size(int x){ //サイズ
		return siz[root(x)];
	}

    bool same(int x, int y){ //グループの判定
		return root(x) == root(y);
	}

    bool unite(int x, int y){ //つなげる
        if((x=root(x))==(y=root(y))) return false;
        if( siz[y] > siz[x] ) swap(x,y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
};
//}}}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    UnionFind uf(n+1);
    vector<int> p(n+1),x(m),y(m);
    reps(i,n){
        cin >> p[i];
    }
    rep(i,m){
        cin >> x[i] >> y[i];
        uf.unite(x[i],y[i]);
    }
    int cnt = 0;
    reps(i,n){
        cnt += (uf.same(i,p[i]));
    }

    cout << cnt << '\n';

    return 0;
}
