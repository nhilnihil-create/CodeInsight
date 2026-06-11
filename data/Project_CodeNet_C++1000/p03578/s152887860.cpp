#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  map<int64_t, int> plan, problemSet;
  
  for (int i = 0; i < N; i++) {
    int64_t D; cin >> D;
    plan[D]++;
  }
  
  int M; cin >> M;
  
  for (int i = 0; i < M; i++) {
    int64_t T; cin >> T;
    problemSet[T]++;
  }
  
  for (auto p : problemSet) {
    
    int tmp = p.first;
    
    if (plan[tmp] < p.second) { cout << "NO" << endl; return 0; }
    
  }
  
  cout << "YES" << endl;
  
}