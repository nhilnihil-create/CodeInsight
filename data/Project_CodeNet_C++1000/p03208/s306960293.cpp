#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K;
  cin >> N >> K;
  
  long long h[N];
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  
  sort(h, h+N);
  
  long long totaldiff = 1e15;
  for (int i = 0; i < N-K+1; i++) {
    totaldiff = min(totaldiff,h[i+K-1]-h[i]);
  }
  
  cout << totaldiff << endl;
  
  return 0;
}