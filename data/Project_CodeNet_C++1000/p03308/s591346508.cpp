#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ma = -100000, mi = 1<<30;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    ma = max(ma, a);
    mi = min(mi, a);
  }
  cout << ma - mi << endl;
}