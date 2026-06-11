#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
//AtCoder解説動画(https://www.youtube.com/watch?v=TdR816rqc3s&feature=youtu.be)からもらった
// (https://atcoder.jp/contests/abc157/submissions/10472433)
struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {} //このコロンってなんですか
	int find(int x){
		if (d[x] < 0) return x; //x:根
		return d[x] = find(d[x]);//x:子 -> xの親の根を返す
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);//根同士をくっつける。
		if ( x ==  y) return false ; 
		/*連結成分が一致してるんだったらfalse返す。
			minimum spanning tree (クラスカル法と言うのをやるときに、くっつけたかどうかを取れると嬉しい.
			chmin/chmaxみたいなノリかな
		 */
		if ( d[x] > d[y]) swap(x,y);//xの方が大きいようにする（ただしサイズは負デモっているので不等号が逆）
		d[x] += d[y] ; //xにyをくっつける.
		d[y] = x;
		return true; 
	}
	bool same(int x, int y) { return find(x) == find(y) ; }
	int size(int x) { return -d[find(x)];}
};
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> x(m), y(m), z(m);
	// TODO 要素　n じゃなくて　m えむ　えむ 
	rep(i,m){
		cin >> x[i] >> y[i] >> z[i];
		--x[i], --y[i];
	}

	UnionFind uf(n);
	rep(i,m){
		uf.unite(x[i], y[i]);
	}

	map<int, bool> seen;
	int ans = 0;
	rep(i,n){
		if(seen[uf.find(i)]) continue;
		seen[uf.find(i)] = true;
		ans++;
	}
	cout << ans << endl;
}
