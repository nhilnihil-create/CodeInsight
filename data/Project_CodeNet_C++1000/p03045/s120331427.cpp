#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vi par,ran;

void init(int n) {
  rep(i,n) {
    par.push_back(i);
    ran.push_back(0);
  }
}

int find(int x) {
  if(par[x]==x) return x;
  return x=find(par[x]);
}

void unite(int x,int y) {
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ran[x]<ran[y]) par[x]=y;
  else {
    par[y]=x;
    if(ran[x]==ran[y]) ran[x]++;
  }
}

bool same(int x,int y) {
  return find(x)==find(y);
}

int main() {
  int N,M;
  cin >> N >> M;
  vi X(M),Y(M),Z(M);
  init(N);
  rep(i,M) {
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--;Y[i]--;
    unite(X[i],Y[i]);
  }
  
  int ans=1;
  rep2(i,1,N) {
    if(!same(0,i)) {
      unite(0,i);
      ans++;
    }
  }
  
  cout << ans << endl;
}