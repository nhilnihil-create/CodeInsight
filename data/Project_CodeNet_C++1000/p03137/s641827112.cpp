#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, M; cin >> N >> M;
  
  if (M <= N) { cout << 0 << endl; return 0; }
  
  vector<int> vec(M); priority_queue<int> memo;
  
  for (int i = 0; i < M; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  int ans = vec.back() - vec.front();
  
  for (int i = 0; i < M - 1; i++) {
    
    int tmp = vec[i + 1] - vec[i];
    
    memo.push(tmp);
    
  }
  
  for (int i = 0; i < N - 1; i++) {
    
    ans -= memo.top();
    
    memo.pop();
    
  }
  
  cout << ans << endl;
  
}