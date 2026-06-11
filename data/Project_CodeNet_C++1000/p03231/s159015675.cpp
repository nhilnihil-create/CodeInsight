#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, M; cin >> N >> M;
  
  string S, T; cin >> S >> T;
  
  int64_t L = N / __gcd(N, M) * M;
  
  map<int64_t, char> memo;
  
  for (int i = 0; i < N; i++) {
    
    int64_t key = i * (L / N) + 1;
    
    memo[key] = S.at(i);
    
  }
  
  for (int i = 0; i < M; i++) {
    
    int64_t key = i * (L / M) + 1;
    
    if (memo.count(key)) {
      
      if (memo.at(key) != T.at(i)) { cout << -1 << endl; return 0; }
      
    }
    
  }
  
  cout << L << endl;
  
}