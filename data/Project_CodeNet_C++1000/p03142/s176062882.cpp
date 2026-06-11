#include<iostream>
#include<string>
#include<cstring>
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
#define PI 3.141592653589793

int depth[202020];
vector<int> to[202020], muka[202020];
bool seen[202020];
vector<int> order;

void rec(int v) {
    seen[v] = true;
    for (auto next : to[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next);
    }
    order.push_back(v);
}

int main(){
  int N, M; cin >> N >> M;
  rep(i, N+M-1){
    int a, b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b); muka[b].push_back(a);
  }
  rep(i, N){
    if(muka[i].size()==0) rec(i);
  } 
  reverse(order.begin(), order.end());
  int ans[N] = {};
  for(int i: order){
    for(int c: to[i]){
      depth[c] = max(depth[c], depth[i]+1);
    }
  }
  rep(i, N){
    for(auto c: to[i]){
      if(depth[c]==depth[i]+1){
        ans[c] = i+1;
      }
    }
  }
  rep(i, N){
    cout << ans[i] << endl;
  }
}