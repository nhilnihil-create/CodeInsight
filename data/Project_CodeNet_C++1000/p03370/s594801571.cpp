#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, mmin, msum;
  cin >> N >> X;
  vector<int> m(N);
  for(int i = 0; i<N; i++) cin >> m[i];
  mmin = m[0];
  msum = m[0];
  for(int i = 1; i<N; i++) {
    mmin = min(mmin, m[i]);
    msum += m[i];
  }
  
  X -= msum;
  int q = X / mmin;
  
  cout << N + q << endl;
}
