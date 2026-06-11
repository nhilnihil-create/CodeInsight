#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  int n = N;
  int g = X;
  for (int i = 0; i < N; i++) {
    int m;
    cin >> m;
    X -= m;
    g = min(m, g);
  }
  n += X / g;
  
  cout << n << endl;
}
