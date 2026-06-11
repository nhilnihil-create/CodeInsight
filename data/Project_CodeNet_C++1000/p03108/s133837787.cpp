#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> par;
vector<ll> siz;

int root(int x){
  if(par.at(x)==-1) return x;
  return par.at(x) = root(par.at(x));
}

bool same(int x, int y){
  return root(x)==root(y);
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x==y) return;
  if(siz.at(x) < siz.at(y)) swap(x, y);
  par.at(y) = x;
  siz.at(x) += siz.at(y);
  
}
ll size(int x){
  return siz.at(root(x));
}

int main() {
  ll N, M;
  cin >> N >> M;
  par = vector<int> (N, -1);
  siz = vector<ll> (N, 1);
  vector<ll> ans (M, 0);
  
  int A, B;
  vector<P> node(M);
  rep(i, M){
    cin >> A >> B;
    node.at(i) = make_pair(--A, --B);
  }
  
  ans.at(M-1) = (N*(N-1)) / 2;

  for(int i=M-1; i>=1; --i){
    int x, y;
    tie(x, y) = node.at(i);
    
    if(same(x, y)) ans.at(i-1) = ans.at(i);
    else{
     ans.at(i-1) = ans.at(i) - (size(x)*size(y));
   	 unite(x, y);
    }
  }
  
  for(auto e:ans) cout << e << endl;

  return 0;
}