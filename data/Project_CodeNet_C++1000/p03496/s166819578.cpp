#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[N], b, c;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  b = min_element(a,a+N)-a;
  c = max_element(a,a+N)-a;
  cout << 2*N << endl;
  if (-a[b] > a[c]) {
    cout << b+1 << ' ' << N << endl << b+1 << ' ' << N << endl;
    for (int i = N-1; i; i--) {
      cout << i+1 << ' ' << i << endl << i+1 << ' ' << i << endl;
    }
  } else {
    cout << c+1 << " 1\n" << c+1 << " 1\n";
    for (int i = 1; i < N; i++) {
      cout << i << ' ' << i+1 << endl << i << ' ' << i+1 << endl;
    }
  }
}