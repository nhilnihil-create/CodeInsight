#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
   int ans = X;
  for (int i = 0; i < N; i++) {
    int days = 0;
    for (int j = 0; j < D; j++) {
      days = j * A[i] + 1;
      if (D >= days) ans++;
      else break; 
    }  
  }
  cout << ans << endl;
}