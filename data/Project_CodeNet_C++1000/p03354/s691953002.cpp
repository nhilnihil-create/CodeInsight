//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

//引用元
//http://drken1215.hatenablog.com/entry/2019/03/03/224600
//union くっつける
//find  どのグループか調べる
struct UnionFind {
    vector<LL> parent;
    
    UnionFind(LL n) : parent(n, -1) { }
    void init(LL n) { parent.assign(n, -1); }
    
    //xの属している木の根っこを返す
    LL root(LL x) {
        if (parent[x] < 0) return x;
        else return parent[x] = root(parent[x]);//経路圧縮
    }
    
    LL size(LL x) {return -parent[root(x)];}//xの属する木の要素数を求める
    bool is_same_tree(LL x,LL y) {return root(x)==root(y);}
    
    bool merge(LL x,LL y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);//xの親の方がyの親より小さくなるようにする
        parent[x] += parent[y];//経路の長さを加算
        parent[y] = x;//yの親をxとする
        return true;
    }
};

LL N,M;
LL p[100001];
LL rev_p[100001];//iがp[j]に格納されている時rev_p[i] = jとする
vector<pair<LL,LL>> xy;
 
LL ans = 0;

void solve(){
	UnionFind uf(N+1);//i,jが同じグループに所属=iとjは交換可能　なことを表す
	for(int i=0;i<M;i++){
		LL x = xy[i].first;
		LL y = xy[i].second;
		uf.merge(x,y);
	}

	for(int i=1;i<=N;i++){
		if(i==p[i]){
			ans++;
			continue;
		}
		//rev_p[i]:iが格納されているインデックス
		if(uf.is_same_tree(i,rev_p[i])){
			//インデックスi,rev_p[i]の位置にある数を交換
			LL x = i;
			LL p_x = p[x];
			LL y = rev_p[i];
			LL p_y = p[y];
			ans++;
			p[x] = p_y;
			p[y] = p_x;
			rev_p[p_x] = y;
			rev_p[p_y] = x;
			continue;
		}
	}
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
    	cin >> p[i];
    	rev_p[p[i]] = i;
    }
    for(int i=0;i<M;i++){
    	LL x,y;
    	cin >> x >> y;
    	xy.push_back(pair<LL,LL>(x,y));
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}