#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t ans = 0;
  
  vector<int64_t> vecA(N), vecB(N), vecC(N);
  
  for (int i = 0; i < N; i++) cin >> vecA[i];
  for (int i = 0; i < N; i++) cin >> vecB[i];
  for (int i = 0; i < N; i++) cin >> vecC[i];
  
  sort(vecA.begin(), vecA.end());
  sort(vecB.begin(), vecB.end());
  sort(vecC.begin(), vecC.end());
  
  for (int i = 0; i < N; i++) {
    
    int64_t key = vecB[i];
    
    auto itrOfvecA = lower_bound(vecA.begin(), vecA.end(), key);
    auto itrOfvecC = upper_bound(vecC.begin(), vecC.end(), key);
    
    if (itrOfvecC == vecC.end()) break;
    
    int64_t numberOfvecA = distance(vecA.begin(), itrOfvecA);
    int64_t numberOfvecC = distance(itrOfvecC, vecC.end());
    
    ans += numberOfvecA * numberOfvecC;
    
  }
  
  cout << ans << endl;
  
}