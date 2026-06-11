#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  vector<int> c(N, -1);
  bool ok = true;
  queue<int> Q;
  c[0] = 0;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (c[w] == -1){
        c[w] = 1 - c[v];
        Q.push(w);
      } else if (c[w] == c[v]){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << (long long) N * (N - 1) / 2 - M << endl;
  } else {
    vector<int> cnt(2, 0);
    for (int i = 0; i < N; i++){
      cnt[c[i]]++;
    }
    cout << (long long) cnt[0] * cnt[1] - M << endl;
  }
}