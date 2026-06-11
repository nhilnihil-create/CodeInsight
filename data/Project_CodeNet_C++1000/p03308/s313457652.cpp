#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int M = 0;
  int m = 1000000000;
  
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a >= M) M = a;
    if (a <= m) m = a;
  }
  cout << M - m << endl;
}
