#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> siz;

    UnionFind(int N) : par(N),siz(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        siz.assign(N,-1);
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if(siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx]+=siz[ry];
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
      return -siz[root(x)];
    }
};

int main(){
  ll n,m;
  cin >> n >> m;
  UnionFind tree(n);
  vector<ll> a(m),b(m);
  for(int i=0;i<m;++i){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  ll su=n*(n-1)/2;
  vector<ll> ans;
  for(int i=0;i<m;++i){
    ans.push_back(su);

    ll A=a[m-1-i];
    ll B=b[m-1-i];
    if(tree.same(A,B)){
      continue;
    }else{
      ll sa=tree.size(A);
      ll sb=tree.size(B);
      //cout << sa << " " << sb << endl;
      su-=sa*sb;
      tree.unite(A,B);
    }
  }
  reverse(ans.begin(),ans.end());
  int si=ans.size();
  for(int i=0;i<si;++i){
    cout << ans[i] << endl;
  }
  return 0;
}
