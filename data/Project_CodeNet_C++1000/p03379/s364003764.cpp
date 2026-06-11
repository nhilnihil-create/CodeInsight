#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    y[i] = x[i];
  }  
  sort(x.begin(), x.end());

  for (int i = 0; i < N; i++) {
    if (y[i] <= x[(N-1)/2]) cout << x[N/2] << endl;
    else cout << x[N/2 - 1] << endl;
  } 
}