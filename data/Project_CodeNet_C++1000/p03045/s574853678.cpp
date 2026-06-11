#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct UnionFind {
    // 親ノードの番号を持つメンバ変数
    // ただし自分が親の時は-x(xは自身を含めた子ノードの数)
    vector<int> par;
    
    //　コンストラクタでの初期化1(初期値-1を持つn次元配列)
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    // 与えられたノードの親ノードの番号を返すメンバ関数
    int root(int x) {
        // もしも親ノードが0以下なら、それは初期値なので自身が親
        if (par[x] < 0) return x;
        // 親ノードを再帰的に一番上までたどって返す
        // 単にroot(par[x])ではなく代入してるのは、根に直接張り直すため
        else return par[x] = root(par[x]);
    }
    
    // もし根が同じかどうかの判定
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    // ２つの根をマージする処理
    bool merge(int x, int y) {
        // 根をたどって、同じなら何もしない
        x = root(x); y = root(y);
        if (x == y) return false;

        // xもyも今は親ノードなので、子の数を比べる
        if (par[x] > par[y]) swap(x, y); // merge technique

        // 小さい方を親ノードにする
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    // 親ノードに入っている番号*-1 = この木のノード数を返す。
    int size(int x) {
        return -par[root(x)];
    }
};

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    vector<ll> A(M);
    vector<ll> B(M);

    REP(i, M){
        ll c;
        cin >> A[i] >> B[i] >> c;
        A[i]--;
        B[i]--;
    }

    UnionFind uf(N);

    // 辺を1つずつ足していく
    REP(i, M){


        ll x = A[M-i-1];
        ll y = B[M-i-1];

        // 同じ木に属すなら処理終了
        if(uf.issame(x, y)) continue;

        //最後にマージ処理をする
        uf.merge(x, y);
    }

    map<ll,ll> MAP;

    REP(i, N){
        MAP[uf.root(i)]++;
    }

    cout << MAP.size() << endl;

    return 0;
}