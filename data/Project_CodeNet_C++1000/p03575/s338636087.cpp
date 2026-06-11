#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
struct UnionFind{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }
    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  vi a(m);
  vi b(m);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  rep(i,m){
    UnionFind tree(n);//初期化
    bool z = false;
    rep(j, m){
      if (j == i){//i番目の橋をつなげない
        continue;
      }
      tree.unite(a[j],b[j]);
    }
    rep(j, n - 1){
      if (!tree.same(0,j+1)){//一つでも根が違う橋があればans++
        z = true;
      }
    }
    if(z){
      ans++;
    }
  }
  print(ans);
}
