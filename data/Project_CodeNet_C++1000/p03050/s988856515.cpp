#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  long long int ans = 0;
  for (long long int X = 1; X * X < N; X++) {
    if (N % X != 0) continue;
    
    long long int M = N / X - 1;
    if (M >= 0 && X < M) ans += M;
  }
  cout << ans << endl;
}