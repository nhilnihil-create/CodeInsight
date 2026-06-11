//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入
// UnionFind
struct UnionFind {
    vector< int > data;
    
    UnionFind(int sz) {
        data.assign(sz, -1);
    }
 
    bool unite(int x, int y) {//要素xとyの各々の木を併合（もともと同じ木ならfalse）
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    
    int find(int k) {//要素kが属する木の根を得る
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }
    
    int size(int k) {//要素kが属する木の要素数
        return (-data[find(k)]);
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }

};

int main(){
    
    int N,M;
    cin >> N >> M;
    UnionFind A(N);
    int x,y,z;
    REP(i,M){
        cin >> x >> y >>z;
        x--;
        y--;
        A.unite(x,y);
    }
    set<int> cnt;
    int num;
    REP(i,N){
        num=A.find(i);
        cnt.insert(num);
    }
    cout << cnt.size() << endl;
    
}