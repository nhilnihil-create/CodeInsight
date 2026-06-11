#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  vector<int64_t> vecA(N);
  
  for (int i = 0; i < N; i++) cin >> vecA[i];
  
  vector<int64_t> vecB(N);
  
  for (int i = 0; i < N; i++) cin >> vecB[i];
  
  int64_t sum = 0;
  
  for (int i = 0; i < N; i++) {
    
    int64_t tmpA = vecA[i], tmpB = vecB[i];
    
    if (tmpA < tmpB) sum += (tmpB - tmpA) / 2;
    
    if (tmpB < tmpA) sum -= tmpA - tmpB;
    
  }
  
  if (sum < 0) cout << "No" << endl;
  
  else cout << "Yes" << endl;
  
}