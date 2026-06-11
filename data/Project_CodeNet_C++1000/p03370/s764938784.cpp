#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int N, X, s = 0, t = 1001;
  cin >> N >> X; 
  vector<int> m(N);
  for (int i = 0; i < N; i++) {
    cin >> m[i];
    s += m[i];
    t = min(t, m[i]);
  }
  
  cout << N + (X-s)/t << endl;
}