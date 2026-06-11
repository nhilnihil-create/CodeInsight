#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>
#include <random>
#include <cstring>
#define mod  1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back

using namespace std;

using ll = long long;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

const int N_MAX = 100005;
const int M_MAX = 200005;

struct Edge {
  int to;
  ll cost;
};

int N, M;
vector<int> L(M_MAX), R(M_MAX);
vector<ll> D(M_MAX);
vector<Edge> E[M_MAX];
vector<ll> pos(N_MAX, LLONG_MAX);
vector<bool> confirm(N_MAX, false);

bool dfs(int curr){
  if(confirm[curr]) return true;
  confirm[curr] = true;
  for(auto e : E[curr]){
    if(pos[e.to] == LLONG_MAX){
      pos[e.to] = pos[curr] + e.cost;
      if(!dfs(e.to)) return false;
    } else {
      if(pos[e.to] != pos[curr] + e.cost) return false;
    }
  }
  return true;
}

int main(){
  cin >> N >> M;
  // if(M == 0){cout << "Yes" << endl; return 0;}
  int start = N_MAX;
  for(int i = 0; i < M; i++){
    cin >> L[i] >> R[i] >> D[i];
    E[L[i]].push_back({R[i],  D[i]});
    E[R[i]].push_back({L[i], -D[i]});
    start = min({start, R[i], L[i]});
  }

  pos[start] = 0;
  bool ok = true;
  for(int i = start; i < N + 1; i++){
    if(!confirm[i] && !dfs(i)){
      ok = false;
      break;
    }
  }
  
  // for(int i = 0; i < N + 1; i++) cerr << i << ": " << pos[i] << endl;
  
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
