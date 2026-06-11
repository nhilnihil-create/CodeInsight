#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long a;
  long long min = 1000000000;
  long long max = -1;
  for (int i=0; i <N; i++) {
    cin >> a;
    if (a < min) {
      min = a;
    }
    if (a > max) {
      max = a;
    }
  }
  cout << max - min  << endl;
}