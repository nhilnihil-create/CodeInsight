#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  
  string S;
  cin >> S;
  
  
  vector<int> a(N, 0);
  for (int i = 1; i < N; i++) {
    if (S[i] == 'C' && S[i-1] == 'A') {
      a[i] = 1;
    }
  }
  
  vector<int> sum(N+1, 0);
  
  for (int i = 0; i < N; i++) {
    sum[i+1] = sum[i] + a[i];
  }
  
  
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    
    cout << sum[r] - sum[l] << endl;
  }
}