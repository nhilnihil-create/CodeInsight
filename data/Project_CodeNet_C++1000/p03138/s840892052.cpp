#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, K;
  
  cin >> N >> K;
  
  vector<long long> A;
  vector<long long> A_bits(60, 0);
  
  for (int i = 0; i < N; i++) {
    long long in;
    
    cin >> in;
    
    A.push_back(in);
    
    for (int j = 0; j < 60; j++) {
      if (in & (1ll << j)) {
        A_bits[j]++;
      }
    }
  }
  
  long long x = 0ll;
  long long ans = 0ll;
  
  for (int i = 60; i >= 0; i--) {
    if (A_bits[i] < N - A_bits[i] && (x | (1ll << i)) <= K) {
      x |= 1ll << i;
    }
  }
  
  for (int i = 0; i < N; i++) {
    ans += A[i] ^ x;
  }
  
  cout << ans << endl;
  
  return 0;
}