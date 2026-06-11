#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K; cin >> N >> K; int dif = pow(10, 9) + 1;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i + K - 1 < N; i++) {
    
    int tmp = vec[i + K - 1] - vec[i];
    
    dif = min(dif, tmp);
    
  }
  
  cout << dif << endl;
  
}