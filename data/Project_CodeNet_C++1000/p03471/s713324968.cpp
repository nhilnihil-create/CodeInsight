#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, Y;
  cin >> N >> Y;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; i+j <= N; j++) {
      if (i*10000ll+j*5000ll+(N-i-j)*1000ll == Y) {
        cout << i << ' ' << j << ' ' << N-i-j;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1";
}