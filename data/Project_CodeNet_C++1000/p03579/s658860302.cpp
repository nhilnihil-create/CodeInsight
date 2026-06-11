#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int color[100000];
vector<int> to[100000];


bool DFS(int x, int C){
  color[x] = C;
  for(int a: to[x]){
    if(color[a]==C) return false;
    if(color[a]==-1 && !DFS(a, 1-C)) return false;
  }
  return true;
}


int main(){
  int N, M; cin >> N >> M;
  rep(i, N)color[i]=-1;
  rep(i, M){
    int a, b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b); to[b].push_back(a);
  }
  if(DFS(0,0)){
    int B=0, W=0;
    rep(i, N){
      if(color[i]==0) B++;
      else W++;
    }
    cout << (ll) B*W - M << endl; return 0;
  }
  cout << (ll) N*(N-1)/2 - M << endl;
}