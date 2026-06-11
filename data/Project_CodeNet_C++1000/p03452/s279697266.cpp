#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>W;
int root(int v) {
  if (v == par[v]) return v;
  int r = root(par[v]);
  W[v] += W[par[v]];
  return par[v] = r;
}
int wei(int v) {
  int k = root(v);
  return W[v];
}
//W[a] - W[b] = w 
int unit(int a, int b, int w) {
  w += wei(b);
  w -= wei(a);
  b = root(b);
  a = root(a);
  par[a] = b;
  W[a] = w;
}
bool same(int a, int b) {
  return root(a) == root(b);
}
int dif_w(int a, int b) {
  return wei(a) - wei(b);
}
int main () {
  int N, M;
  cin >> N >> M;
  par.resize(N);
  W.resize(N);
  for (int i = 0; i < N; i ++) {
    par[i] = i;
    W[i] = 0;
  }
  for (int i = 0; i < M; i ++) {
    int l, r, d;
    cin >> l >> r >> d;
    l --;
    r --;
    if (same(l, r)) {
      //cout << dif_w(r, l) << endl;
      if (dif_w(r, l) != d){
        cout << "No" << endl;
        return 0;
      }
    }
    else unit(r, l, d);
    //cout << i << endl;
  }
  cout << "Yes" << endl;
}

