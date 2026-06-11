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

struct edge{
  int to, cost;
};

int main(){
  int N, M;
  cin >> N >> M;

  vector<edge> G[N + 1];
  for(int i = 0; i < M; i++){
    int L, R, D;
    cin >> L >> R >> D;
    G[L].push_back(edge{R, D});
    G[R].push_back(edge{L, -D});
  }

  /*for(int i = 1; i <= N; i++){
    for(int j = 0; j < G[i].size(); j++){
      cout << i << j << " " << G[i][j].to << G[i][j].cost << endl;
    }
  }*/

  bool dfd[N + 1];
  fill(dfd, dfd + N + 1, false);
  ll pos[N + 1];

  int ind = 1;
  while(ind <= N){
    if(dfd[ind] == false){
      pos[ind] = 0LL;
      dfd[ind] = true;
      stack<int> st;
      st.push(ind);

      //dfs========================================
      while(st.size()){
        int p = st.top();
        st.pop();
        for(int i = 0; i < G[p].size(); i++){
          int t = G[p][i].to;
          int c = G[p][i].cost;
          if(dfd[t] == false){
            pos[t] = pos[p] + c;
            dfd[t] = true;
            st.push(t);
          }
          else{
            if(pos[t] != pos[p] + c){
              cout << "No" << endl;
              return 0;
            }
          }
        }
      }
      //============================================
    }
    else{
      ind++;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
