#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int X[N], Y[N];
  for (int i = 0; i < N; i++) {
    cin >> X[i];
    Y[i] = X[i];
  }
  
  sort(Y, Y+N);
  
  int middle1 = Y[N/2 -1], middle2 = Y[N/2];
  
  for (int i = 0; i < N; i++) {
    if (X[i] <= Y[N/2-1]) {
      cout << middle2 << endl;
    } else {
      cout << middle1 << endl;
    }
  }
  
}