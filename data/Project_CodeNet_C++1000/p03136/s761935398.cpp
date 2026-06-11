#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L, m=0, S=0;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> L;
    m=max(m, L);
    S+=L;
  }
  if (S>2*m) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

