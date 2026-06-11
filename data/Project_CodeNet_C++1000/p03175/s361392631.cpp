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

vector<int> to[101010];
ll color=1;
ll dp[101010][2];

int DFS(int a, int p){
  for(int u: to[a]){
    if(u==p) continue;
    DFS(u, a);
    dp[a][0]*=(dp[u][0]+dp[u][1])%mod; dp[a][0]%=mod;
    dp[a][1]*=(dp[u][0]); dp[a][1]%=mod;
  }
  return (dp[a][0]+dp[a][1])%mod;
}
  


int main(){
  int N; cin >> N;
  rep(i, N-1){
    int x, y; cin >> x >> y; x--; y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  rep(i, 101010){
    rep(j, 2){
      dp[i][j] = 1;
    }
  }
  cout << DFS(0, -1) << endl;
}