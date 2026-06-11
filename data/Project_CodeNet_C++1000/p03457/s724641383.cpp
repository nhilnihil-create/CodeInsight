#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  }
 t[0]=0; x[0]=0; y[0]=0;

  for (int i = 0; i < N; i++) {
    int dt = t[i + 1] - t[i];
    int dxy = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]); 
    if (dxy > dt || dt % 2 != dxy % 2) {cout << "No" << endl; return 0;}
  }
 
  cout << "Yes"<< endl;
}