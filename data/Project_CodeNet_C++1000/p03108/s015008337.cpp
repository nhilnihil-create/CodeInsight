#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;




struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N, -1){}

  // Aのrootを調べる
  int root(int A){
    if (par[A] < 0) return A;  // マイナスならそれはroot
    return par[A] = root(par[A]);
  }

  // rootの値をプラスに戻して返す(サイズ)
  int size(int A){
    return -par[root(A)];
  }

  bool same(int A, int B){
    return root(A) == root(B);
  }

  void connect(int A, int B){
    A = root(A);  
    B = root(B);
    if (size(A) < size(B))
      swap(A, B);        
    par[A] += par[B];  
    par[B] = A;
  }
};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    UnionFind tree(n);
    vector<ll> ans(m);
    ans[m - 1] = n * (n - 1) / 2;
    for (int i = m - 1; i >= 1; i--){
        if (!tree.same(a[i], b[i])){
            ll res = tree.size(a[i]) * tree.size(b[i]);
            ans[i - 1] = ans[i] - res;
            tree.connect(a[i], b[i]);
        }
        else ans[i - 1] = ans[i];
    }
    rep(i, m) cout << ans[i] << endl;
}