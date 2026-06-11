#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
template <typename T>
struct UnionFind {
   vector<T> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
 
   UnionFind(T N) : par(N) { //最初は全てが根であるとして初期化
        for(T i = 0; i < N; i++) par[i] = i;
   }
 
   int root(T x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
   }
 
   void unite(T x, T y) { // xとyの木を併合
       T rx = root(x); //xの根をrx
       T ry = root(y); //yの根をry
       if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
       par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
   }
 
   bool same(T x, T y) { // 2つのデータx, yが属する木が同じならtrueを返す
       T rx = root(x);
       T ry = root(y);
       return rx == ry;
   }
};
 
int main(){

    ll n,m;
    cin >> n >> m;
    vector<ll> data(n);
    rep(i,n) cin >> data[i];

    UnionFind<ll> tree(n);

    rep(i,m){
        ll x,y;
        cin >> x >> y;
        tree.unite(x-1,y-1);
    }

    ll cnt=0;
    rep(i,n){
        if(tree.same(i,data[i]-1)){
            cnt++;
        }
    }

    cout << cnt << endl;
 
}