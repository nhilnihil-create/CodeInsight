#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  long long a[50];
  int p = 0;
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
    if(abs(a[p]) < abs(a[i])) {
      p = i;
    }
  }

  cout << 2 * N - 1 << endl;
  for(int i = 0; i < N; ++i) {
    cout << p + 1 << " " << i + 1 << endl;
  }
  if(a[p] < 0) {
    for(int i = N; i > 1; --i) {
      cout << i << " " << i - 1 << endl;
    }
  } else {
    for(int i = 1; i < N; ++i) {
      cout << i << " " << i + 1 << endl;
    }
  }
}
