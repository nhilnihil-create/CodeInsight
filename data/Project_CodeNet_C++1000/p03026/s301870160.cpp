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
const long long INF = 1e16;
typedef long long ll;

int main(){

  int N; cin >> N;

  vector < vector<int> > graph(N);
  for (int i = 0; i < N - 1; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  
  vector <int> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(C.begin(), C.end(), greater<int>());

  int cnt = 1;
  vector <int> D(N);
  D[0] = C[0];
  queue <int> que;
  for (int i = 0; i < graph[0].size(); i++){
    que.push(graph[0][i]);
  }
  
  while (!que.empty()){
    int now = que.front(); que.pop();
    if (D[now] == 0){
      D[now] = C[cnt];
      cnt++;
    }
    
    for (int i = 0; i < graph[now].size(); i++){
      if (D[graph[now][i]] == 0){
        que.push(graph[now][i]);
      }
    }
  }
  
  int M = 0;
  for (int i = 0; i < N; i++){
    int now = i;
    for (int j = 0; j < graph[now].size(); j++){
      int next = graph[now][j];

      if (now < next){
        M += min(D[now], D[next]);
      }
    }
  }
  
  cout << M << endl;

  for (int i = 0; i < N - 1; i++) cout << D[i] << " " ;
  cout << D[N - 1] << endl;
  

  return 0;
}
