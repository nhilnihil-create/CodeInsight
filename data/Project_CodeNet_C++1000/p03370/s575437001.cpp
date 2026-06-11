#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long S;
  cin >> S;
  long long mi = 1<<30;
  for (int i = 0; i < N; ++i) {
    long long a;
    cin >> a;
    S -= a;
    mi = min(mi, a);
  }
  cout << N + S / mi << endl;
}