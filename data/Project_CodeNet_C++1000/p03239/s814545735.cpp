#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, c, t, m=10000000;
  cin >> N >> T;
  for (int i=0; i<N; i++) {
    cin >> c >> t;
    if (t>T) {continue;}
    m=min(m,c);
  }
  if (m==10000000) {
    cout << "TLE" << endl;
  }
  else {
    cout << m << endl;
  }
}

