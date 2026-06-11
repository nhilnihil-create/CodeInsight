#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N; cin >> N;
  
  vector<int64_t> vec(5);
  
  for (int i = 0; i < 5; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  int64_t tmp = vec[0];
  
  if (tmp < N) {
    
    if (N % tmp == 0) cout << 4 + N / tmp << endl;
    
    else cout << 5 + N / tmp << endl;
    
  }
  
  else cout << 5 << endl;
  
}