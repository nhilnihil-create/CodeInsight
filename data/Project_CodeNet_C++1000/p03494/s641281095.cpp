#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N; 
  int K = 1000000;
  for (int i = 0; i < N; i++) {
    int L = 0, x;
    cin >> x;
    while (x % 2 == 0) {
      x /= 2;
      L++;
    }
    if (L < K) {K = L;}
  }
  cout << K << endl;
}