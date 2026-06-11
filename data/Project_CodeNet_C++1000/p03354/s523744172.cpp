#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

vector<int> par;
vector<int> rnk;

void init(int N){
  par.resize(N, 0);
  rnk.resize(N, 0);
  REP(i, N){
    par[i] = i;
  }
}

int find(int X){
  if(par[X] == X){
    return X;
  }else{
    return par[X] = find(par[X]);
  }
}

void unite(int X, int Y){
  X = find(X); Y = find(Y);
  if(X == Y) return;
  if(rnk[X] < rnk[Y]){
    par[X] = Y;
  }else{
    par[Y] = X;
    if(rnk[X] == rnk[Y]) rnk[X]++;
  }
}

bool same(int X, int Y){
  return find(X) == find(Y);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<int> p(N, 0);
  REP(i, N){
    int tmp; cin >> tmp; tmp--;
    p[i] = tmp;
  }
  init(N);
  REP(i, M){
    int x, y; cin >> x >> y; x--; y--;
    unite(x, y);
  }
  int ans = 0;
  REP(i, N){
    if(same(p[i], i)) ans++; // p[i]:行きたい場所、i:今いる場所
  }
  cout << ans << endl;
}