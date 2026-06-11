#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

#define maxN 100000

vector<int> G[maxN];
int col[maxN];

bool dfs(int n){
  for(int i = 0; i < (int)G[n].size(); i++){
    int nxt = G[n][i];
    if(col[nxt] == 0){
      col[nxt] = -col[n];
      if(!dfs(nxt)){
        return false;
      }
    }
    else {
      if(col[nxt] == col[n]){
        return false;
      }
      else {
        //何もしない
      }
    }
  }

  return true;
}

int main(){
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  //0:未確定　1:シロ　-1：黒
  fill(col, col + N, 0);
  col[0] = 1;
  bool isBipGraph = dfs(0);

  ll ans = 0;
  if(isBipGraph){
    //cout << "nibu" << endl;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for(int i = 0; i < N; i++){
      if(col[i] == 1) cnt1++;
      if(col[i] == -1) cnt2++;
    }

    ans = cnt1 * cnt2 - M;
  }
  else {
    ans = (ll)N * (ll)(N - 1) / 2 - M;
  }

  cout << ans << endl;
  return 0;
}
