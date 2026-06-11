#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){

  string s;cin>>s;
  int k;cin>>k;

  set<string>se;
  int n=s.size();
  rep(i,0,n){
    rep(j,1,min(5,n)+1){
      se.insert(s.substr(i,j));
    }
  }

  int count=0;
  for(set<string>::iterator itr=se.begin();itr!=se.end();itr++){
    // out(*itr);
    count++;
    if(count==k){
      out(*itr);
      return 0;
    }
  }

  return 0;
}
