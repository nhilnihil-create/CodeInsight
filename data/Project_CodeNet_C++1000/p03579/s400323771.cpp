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

vvi v;
vi color;

bool dfs(int now,int c) {
  color[now]=c;
  for(int x:v[now]) {
    if(color[x]==c) return false;
    if(!color[x]&&!dfs(x,-c)) return false;
  }
  return true;
}

int main() {
  ll N,M;
  cin >> N >> M;
  v=vvi(N);
  color=vi(N);
  vi A(M),B(M);
  rep(i,M) {
    cin >> A[i] >> B[i];
    A[i]--;B[i]--;
    v[A[i]].push_back(B[i]);
    v[B[i]].push_back(A[i]);
  }
  
  if(dfs(0,1)) {
    int count=0;
    rep(i,N) {
      if(color[i]==1) count++;
    }
    cout << count*(N-count)-M << endl;
  }
  else cout << N*(N-1)/2-M << endl;
}

