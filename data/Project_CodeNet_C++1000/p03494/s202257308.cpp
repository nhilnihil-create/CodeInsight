#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, count = 0;
  cin >> N;
  
  int org[N];
  for (int i=0; i < N; i++) {
    int a;
    cin >> a;
    
    org[i] = a;
  }

  for (;;) {
    int c = 0;
    for (int i=0; i < N; i++) {
      if (org[i] % 2 == 0) {
        c += 1;
        org[i] = org[i]/2;
      }
    }
    if (c != N) {
      break;
    } else {
      count += 1;
    }
  }
  cout << count;
}
