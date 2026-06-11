#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, M; cin >> N >> M;

  vector <int> graph[N], regraph(N);

  for (int i = 0; i < N + M - 1; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    regraph[B]++;
  }
  
  vector <int> order;
  queue <int> que;
  for (int i = 0; i < N; i++){
    if (regraph[i] == 0){
      order.push_back(i);
      que.push(i);
    }
  }
  
  vector <int> ans(N);
  while (!que.empty()){
    int Q = que.front(); que.pop();

    for (int i = 0; i < graph[Q].size(); i++){
      int next = graph[Q][i];
      regraph[next]--;
      if (regraph[next] == 0){
        que.push(next);
        order.push_back(next);
        ans[next] = Q + 1;
      }
    }
  }

  
  for (int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }
  

  return 0;
}
